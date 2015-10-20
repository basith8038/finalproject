/*
* Copyright (c) 2006-2009 Erin Catto http://www.box2d.org
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

/*
 * Base code for CS 251 Software Systems Lab
 * Department of Computer Science and Engineering, IIT Bombay
 *
 */


#include "cs251_base.hpp"
#include "render.hpp"

#ifdef __APPLE__
        #include <GLUT/glut.h>
#else
        #include "GL/freeglut.h"
#endif

#include <cstring>
using namespace std;

#include "dominos.hpp"

namespace cs251
{
  /**  The is the constructor
   * This is the documentation block for the constructor.
   */

  dominos_t::dominos_t()
  {
  	    //Top horizontal shelf
        /** \brief THIS BLOCK CREATES TOP HORIZONTAL SHELF  TO HOLD DOMINOS*/
  { 
    
      b2PolygonShape shape;
      shape.SetAsBox(8.0f, 0.25f);
	
      b2BodyDef bd;
      bd.position.Set(-33.0f, 20.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);    
  }
    //another horizontal shelf
          /** \brief THIS BLOCK CREATES HORIZONTAL SHELF NEXT TO INCLINED PLANE*/
  {
    
      b2PolygonShape shape;
      shape.SetAsBox(5.0f, 0.25f);
  
      b2BodyDef bd;
      bd.position.Set(-11.0f, 19.75f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);   
  }
    //inclined plane
              /** \brief THIS BLOCK CREATES INCLINED PLANENEXT TO HORIZONTAL SHELF*/
  {
    
      b2PolygonShape shape;
      shape.SetAsBox(6.0f, 0.25f, b2Vec2(0.f,0.f), 7.0f);
      b2BodyDef bd;
      bd.position.Set(-1.5f, 23.75f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);   
  }  
    //Dominos
        /** \brief THIS BLOCK CREATES DOMINOES ON TOP HORIZONTAL SHELF */
  {
      b2PolygonShape shape;
      shape.SetAsBox(0.1f, 1.0f);
	
      b2FixtureDef fd;
      fd.shape = &shape;
      fd.density = 20.0f;
      fd.friction = 0.1f;
		
      for (int i = 0; i < 11; ++i)
	     {
	       b2BodyDef bd;
	       bd.type = b2_dynamicBody;
	       bd.position.Set(-35.65f + 1.0f * i, 21.25f);
    	  b2Body* body = m_world->CreateBody(&bd);
    	  body->CreateFixture(&fd);
	     } 
  }

      // horizontal,vertical shelf near domino
            /** \brief THIS BLOCK CREATES HORIZONTAL,VERTICAL SHELFES TO HOLD FALLING BALL,DOMINO*/
  {
      {
      b2PolygonShape shape;
      shape.SetAsBox(3.0f, 0.2f);
  
      b2BodyDef bd;
      bd.position.Set(-21.0f, 17.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
      }
      {
      b2PolygonShape shape;
      shape.SetAsBox(0.2f, 0.5f);
  
      b2BodyDef bd;
      bd.position.Set(-24.0f, 17.2f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
      }
      {
      b2PolygonShape shape;
      shape.SetAsBox(0.2f, 0.5f);
  
      b2BodyDef bd;
      bd.position.Set(-18.0f, 17.2f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
      }
  }
          //Inclined planes
      /** \brief THIS BLOCK CREATES THE BIGGER INCLINED PLANES BELOW DOMINOS SHELF */   
  {
    {
      b2PolygonShape shape;
      shape.SetAsBox(6.0f, 0.25f, b2Vec2(0.f,0.f), 6.0f);

      b2BodyDef bd;
      bd.position.Set(-40.0f, 15.5f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
    }
    {
      b2PolygonShape shape;
      shape.SetAsBox(6.0f, 0.25f, b2Vec2(0.f,0.f), -6.0f);

      b2BodyDef bd;
      bd.position.Set(-32.0f, 10.5f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
    }
    {
      b2PolygonShape shape;
      shape.SetAsBox(6.0f, 0.25f, b2Vec2(0.f,0.f), 6.0f);

      b2BodyDef bd;
      bd.position.Set(-40.0f, 5.5f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
    }
  }
    //small inclined planes
      /** \brief THIS BLOCK CREATES THE SMALLER INCLINED PLANES BELOW DOMINOS SHELF */   
  {
    {
      b2PolygonShape shape;
      shape.SetAsBox(1.0f, 0.25f, b2Vec2(0.f,0.f), 7.0f);

      b2BodyDef bd;
      bd.position.Set(-45.0f, 18.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
    }
    {
      b2PolygonShape shape;
      shape.SetAsBox(1.0f, 0.25f, b2Vec2(0.f,0.f), -7.0f);

      b2BodyDef bd;
      bd.position.Set(-27.0f, 13.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
    }
    {
      b2PolygonShape shape;
      shape.SetAsBox(1.0f, 0.25f, b2Vec2(0.f,0.f), 7.0f);

      b2BodyDef bd;
      bd.position.Set(-45.0f, 8.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
    }
  }
    //horizontal pendulums
        /** \brief THIS BLOCK CREATES PENNDULUMS TO KNOCK THE DOMINOS*/
  {
    {
        b2Body* b2;
        {
          b2PolygonShape shape;
          shape.SetAsBox(0.25f, 0.25f);    
          b2BodyDef bd;
          bd.position.Set(-24.5f, 30.0f);
          b2 = m_world->CreateBody(&bd);
          b2->CreateFixture(&shape, 10.0f);
        }    
        b2Body* b4;
        {
          b2PolygonShape shape;
          shape.SetAsBox(0.5f, 0.5f);
          b2BodyDef bd;
          bd.type = b2_dynamicBody;
          bd.position.Set(-24.5f, 21.0f);
          b4 = m_world->CreateBody(&bd);
          b4->CreateFixture(&shape, 2.0f);
        }
        b2RevoluteJointDef jd;
        b2Vec2 anchor;
        anchor.Set(-24.5f, 30.0f);
        jd.Initialize(b2, b4, anchor);
        m_world->CreateJoint(&jd);
    }
    {
        b2Body* b2;
        {
          b2PolygonShape shape;
          shape.SetAsBox(0.25f, 0.25f);
          b2BodyDef bd;
          bd.position.Set(-22.5f, 30.0f);
          b2 = m_world->CreateBody(&bd);
          b2->CreateFixture(&shape, 10.0f);
        } 
        b2Body* b4;
        {
          b2PolygonShape shape;
          shape.SetAsBox(0.5f, 0.5f);
          b2BodyDef bd;
          bd.type = b2_dynamicBody;
          bd.position.Set(-22.5f, 21.0f);
          b4 = m_world->CreateBody(&bd);
          b4->CreateFixture(&shape, 2.0f);
        }
        b2RevoluteJointDef jd;
        b2Vec2 anchor;
        anchor.Set(-22.5f, 30.0f);
        jd.Initialize(b2, b4, anchor);
        m_world->CreateJoint(&jd);
    }
    {
        b2Body* b2;
        {
          b2PolygonShape shape;
          shape.SetAsBox(0.25f, 0.25f);
          b2BodyDef bd;
          bd.position.Set(-20.5f, 30.0f);
          b2 = m_world->CreateBody(&bd);
          b2->CreateFixture(&shape, 10.0f);
        }
        b2Body* b4;
        {
          b2PolygonShape shape;
          shape.SetAsBox(0.5f, 0.5f);
          b2BodyDef bd;
          bd.type = b2_dynamicBody;
          bd.position.Set(-20.5f, 21.0f);
          b4 = m_world->CreateBody(&bd);
          b4->CreateFixture(&shape, 2.0f);
        }
        b2RevoluteJointDef jd;
        b2Vec2 anchor;
        anchor.Set(-20.5f, 30.0f);
        jd.Initialize(b2, b4, anchor);
        m_world->CreateJoint(&jd);
    }
   {
        b2Body* b2;
        {
          b2PolygonShape shape;
          shape.SetAsBox(0.25f, 0.25f);
          b2BodyDef bd; 
          bd.position.Set(-18.5f, 30.0f);
          b2 = m_world->CreateBody(&bd);
          b2->CreateFixture(&shape, 10.0f);
        }
        b2Body* b4;
        {
          b2PolygonShape shape;
          shape.SetAsBox(0.5f, 0.5f);    
          b2BodyDef bd;
          bd.type = b2_dynamicBody;
          bd.position.Set(-18.5f, 21.0f);
          b4 = m_world->CreateBody(&bd);
          b4->CreateFixture(&shape, 2.0f);
        }
        b2RevoluteJointDef jd;
        b2Vec2 anchor;
        anchor.Set(-18.5f, 30.0f);
        jd.Initialize(b2, b4, anchor);
        m_world->CreateJoint(&jd);
    }
   {
        b2Body* b2;
        {
          b2PolygonShape shape;
          shape.SetAsBox(0.25f, 0.25f);    
          b2BodyDef bd;
          bd.position.Set(-16.5f, 30.0f);
          b2 = m_world->CreateBody(&bd);
          b2->CreateFixture(&shape, 10.0f);
        }
        b2Body* b4;
        {
          b2PolygonShape shape;
          shape.SetAsBox(0.5f, 0.5f);
          b2BodyDef bd;
          bd.type = b2_dynamicBody;
          bd.position.Set(-16.5f, 21.0f);
          b4 = m_world->CreateBody(&bd);
          b4->CreateFixture(&shape, 2.0f);
        }
        b2RevoluteJointDef jd;
        b2Vec2 anchor;
        anchor.Set(-16.5f, 30.0f);
        jd.Initialize(b2, b4, anchor);
        m_world->CreateJoint(&jd);
    }
  }
      //sphere near dominos
     /** \brief THIS BLOCK CREATES SPHERE TO BE PLACED NEXT TO THE DOMINOS */
  {
      b2Body* spherebody;
  
      b2CircleShape circle;
      circle.m_radius = 0.5;
  
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 100.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
  
      //for (int i = 0; i < 10; ++i)
      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(-38.0f, 20.5f);
      spherebody = m_world->CreateBody(&ballbd);
      spherebody->CreateFixture(&ballfd);
  }
  //horizontal shelf,seesaw,box,sphere
       /** \brief THIS BLOCK CREATES HORIZONTAL SHELF,SEESAW,BOX,SPHERE SYSTEMT LEFT OF MIDDLE PULLEY */
    {
     // horizontal shelf
      b2PolygonShape shape;
      shape.SetAsBox(7.0f, 0.1f);
  
      b2BodyDef bd;
      bd.position.Set(10.5f, 28.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
      //triangular wedge
      b2Body* sbody;
      b2PolygonShape poly;
      b2Vec2 vertices[3];
      vertices[0].Set(-1,0);///sets each of the vertices of wedge
      vertices[1].Set(1,0);///sets each of the vertices of wedge
      vertices[2].Set(0,1.5);///sets each of the vertices of wedge
      poly.Set(vertices, 3);
      b2FixtureDef wedgefd;
      wedgefd.shape = &poly;///fixes the shape of wedgefd
      wedgefd.density = 10.0f;///fixes the density of wedgefd
      wedgefd.friction = 0.0f;///fixes the friction coefficient of wedgefd
      wedgefd.restitution = 0.0f;///fixes the coefficient of restitution of wedgefd
      b2BodyDef wedgebd;
      wedgebd.position.Set(10.5f, 28.0f);///sets the position of wedge
      sbody = m_world->CreateBody(&wedgebd);///creates the wedge
      sbody->CreateFixture(&wedgefd);///fixes the shape of wedge as defined
      
      //The plank on top of the wedge
      shape.SetAsBox(5.08f, 0.1f);
      b2BodyDef bd2;
      bd2.position.Set(10.5f, 29.5f);
      bd2.type = b2_dynamicBody;
      b2Body* body = m_world->CreateBody(&bd2);
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.f;
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;
      body->CreateFixture(fd2);

      b2RevoluteJointDef jd;
      b2Vec2 anchor;
      anchor.Set(10.5f,29.0f);
      jd.Initialize(sbody, body, anchor);
      m_world->CreateJoint(&jd);
      //box beside the see saw
      b2PolygonShape shape2;
      shape2.SetAsBox(1.0f,0.5f);
      b2BodyDef bd3;
      bd3.position.Set(4.5f, 28.5f);
      //bd3.type = b2_dynamicBody;
      b2Body* body3 = m_world->CreateBody(&bd3);
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 0.1f;
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;
      body3->CreateFixture(fd3);
     ///sphere on the box
     b2Body* spherebody;
  
      b2CircleShape circle;
      circle.m_radius = 1.0;
  
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 3.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(4.5f, 30.5f);
      spherebody = m_world->CreateBody(&ballbd);
      spherebody->CreateFixture(&ballfd);
    }
 //horizontal shelf,seesaw,box,sphere SYSTEMS
       /** \brief THIS BLOCK CREATES HORIZONTAL SHELF,SEESAW,BOX,SPHERE SYSTEMS TO RIGHT OF MIDDLE PULLEY */
 {
    {
     // horizontal shelf
      b2PolygonShape shape;
      shape.SetAsBox(7.0f, 0.1f);
  
      b2BodyDef bd;
      bd.position.Set(29.5f, 28.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
      //triangular wedge
      b2Body* sbody;
      b2PolygonShape poly;
      b2Vec2 vertices[3];
      vertices[0].Set(-1,0);///sets each of the vertices of wedge
      vertices[1].Set(1,0);///sets each of the vertices of wedge
      vertices[2].Set(0,1.5);///sets each of the vertices of wedge
      poly.Set(vertices, 3);
      b2FixtureDef wedgefd;
      wedgefd.shape = &poly;///fixes the shape of wedgefd
      wedgefd.density = 10.0f;///fixes the density of wedgefd
      wedgefd.friction = 0.0f;///fixes the friction coefficient of wedgefd
      wedgefd.restitution = 0.0f;///fixes the coefficient of restitution of wedgefd
      b2BodyDef wedgebd;
      wedgebd.position.Set(29.5f, 28.0f);///sets the position of wedge
      sbody = m_world->CreateBody(&wedgebd);///creates the wedge
      sbody->CreateFixture(&wedgefd);///fixes the shape of wedge as defined
      
      //The plank on top of the wedge
      shape.SetAsBox(5.18f, 0.1f);
      b2BodyDef bd2;
      bd2.position.Set(29.5f, 29.5f);
      bd2.type = b2_dynamicBody;
      b2Body* body = m_world->CreateBody(&bd2);
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.f;
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;
      body->CreateFixture(fd2);

      b2RevoluteJointDef jd;
      b2Vec2 anchor;
      anchor.Set(29.5f,29.0f);
      jd.Initialize(sbody, body, anchor);
      m_world->CreateJoint(&jd);
      //box beside the see saw
      b2PolygonShape shape2;
      shape2.SetAsBox(1.0f,0.5f);
      b2BodyDef bd3;
      bd3.position.Set(35.6f, 28.5f);
      //bd3.type = b2_dynamicBody;
      b2Body* body3 = m_world->CreateBody(&bd3);
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 0.1f;
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;
      body3->CreateFixture(fd3);
     ///sphere on the box
     b2Body* spherebody;
  
      b2CircleShape circle;
      circle.m_radius = 1.0;
  
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 3.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(35.6f, 30.5f);
      spherebody = m_world->CreateBody(&ballbd);
      spherebody->CreateFixture(&ballfd);
    } 
    {
     // horizontal shelf
      b2PolygonShape shape;
      shape.SetAsBox(7.0f, 0.1f);
  
      b2BodyDef bd;
      bd.position.Set(43.0f, 23.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
      //triangular wedge
      b2Body* sbody;
      b2PolygonShape poly;
      b2Vec2 vertices[3];
      vertices[0].Set(-1,0);///sets each of the vertices of wedge
      vertices[1].Set(1,0);///sets each of the vertices of wedge
      vertices[2].Set(0,1.5);///sets each of the vertices of wedge
      poly.Set(vertices, 3);
      b2FixtureDef wedgefd;
      wedgefd.shape = &poly;///fixes the shape of wedgefd
      wedgefd.density = 10.0f;///fixes the density of wedgefd
      wedgefd.friction = 0.0f;///fixes the friction coefficient of wedgefd
      wedgefd.restitution = 0.0f;///fixes the coefficient of restitution of wedgefd
      b2BodyDef wedgebd;
      wedgebd.position.Set(43.0f, 23.0f);///sets the position of wedge
      sbody = m_world->CreateBody(&wedgebd);///creates the wedge
      sbody->CreateFixture(&wedgefd);///fixes the shape of wedge as defined
      
      //The plank on top of the wedge
      shape.SetAsBox(5.18f, 0.1f);
      b2BodyDef bd2;
      bd2.position.Set(43.0f, 24.5f);
      bd2.type = b2_dynamicBody;
      b2Body* body = m_world->CreateBody(&bd2);
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.f;
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;
      body->CreateFixture(fd2);

      b2RevoluteJointDef jd;
      b2Vec2 anchor;
      anchor.Set(43.0f,24.0f);
      jd.Initialize(sbody, body, anchor);
      m_world->CreateJoint(&jd);
      //box beside the see saw
      b2PolygonShape shape2;
      shape2.SetAsBox(1.0f,0.5f);
      b2BodyDef bd3;
      bd3.position.Set(49.1f, 23.5f);
      //bd3.type = b2_dynamicBody;
      b2Body* body3 = m_world->CreateBody(&bd3);
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 0.1f;
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;
      body3->CreateFixture(fd3);
      ///sphere on the box
      b2Body* spherebody;
  
      b2CircleShape circle;
      circle.m_radius = 1.0;
  
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 3.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(49.1f, 25.5f);
      spherebody = m_world->CreateBody(&ballbd);
      spherebody->CreateFixture(&ballfd);    
    }
    {
     // horizontal shelf
      b2PolygonShape shape;
      shape.SetAsBox(7.0f, 0.1f);
  
      b2BodyDef bd;
      bd.position.Set(56.5f, 18.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
      //triangular wedge
      b2Body* sbody;
      b2PolygonShape poly;
      b2Vec2 vertices[3];
      vertices[0].Set(-1,0);///sets each of the vertices of wedge
      vertices[1].Set(1,0);///sets each of the vertices of wedge
      vertices[2].Set(0,1.5);///sets each of the vertices of wedge
      poly.Set(vertices, 3);
      b2FixtureDef wedgefd;
      wedgefd.shape = &poly;///fixes the shape of wedgefd
      wedgefd.density = 10.0f;///fixes the density of wedgefd
      wedgefd.friction = 0.0f;///fixes the friction coefficient of wedgefd
      wedgefd.restitution = 0.0f;///fixes the coefficient of restitution of wedgefd
      b2BodyDef wedgebd;
      wedgebd.position.Set(56.5f, 18.0f);///sets the position of wedge
      sbody = m_world->CreateBody(&wedgebd);///creates the wedge
      sbody->CreateFixture(&wedgefd);///fixes the shape of wedge as defined
      
      //The plank on top of the wedge
      shape.SetAsBox(5.18f, 0.1f);
      b2BodyDef bd2;
      bd2.position.Set(56.5f, 19.5f);
      bd2.type = b2_dynamicBody;
      b2Body* body = m_world->CreateBody(&bd2);
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.f;
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;
      body->CreateFixture(fd2);

      b2RevoluteJointDef jd;
      b2Vec2 anchor;
      anchor.Set(56.5f,19.0f);
      jd.Initialize(sbody, body, anchor);
      m_world->CreateJoint(&jd);
      //box beside the see saw
      b2PolygonShape shape2;
      shape2.SetAsBox(1.0f,0.5f);
      b2BodyDef bd3;
      bd3.position.Set(62.6f, 18.5f);
      //bd3.type = b2_dynamicBody;
      b2Body* body3 = m_world->CreateBody(&bd3);
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 0.1f;
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;
      body3->CreateFixture(fd3);
     ///sphere on the box
     b2Body* spherebody;
  
      b2CircleShape circle;
      circle.m_radius = 1.0;
  
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 3.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(62.6f, 20.5f);
      spherebody = m_world->CreateBody(&ballbd);
      spherebody->CreateFixture(&ballfd);
    }
 }
     //rightpart
  //horizontal shelf,seesaw,box,sphere SYSTEMS
       /** \brief THIS BLOCK CREATES HORIZONTAL SHELF,SEESAW,BOX,SPHERE SYSTEMS TO RIGHT OF MIDDLE PULLEY */
 {
    {
     // horizontal shelf
      b2PolygonShape shape;
      shape.SetAsBox(7.0f, 0.1f);
  
      b2BodyDef bd;
      bd.position.Set(29.5f, 28.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
      //triangular wedge
      b2Body* sbody;
      b2PolygonShape poly;
      b2Vec2 vertices[3];
      vertices[0].Set(-1,0);///sets each of the vertices of wedge
      vertices[1].Set(1,0);///sets each of the vertices of wedge
      vertices[2].Set(0,1.5);///sets each of the vertices of wedge
      poly.Set(vertices, 3);
      b2FixtureDef wedgefd;
      wedgefd.shape = &poly;///fixes the shape of wedgefd
      wedgefd.density = 10.0f;///fixes the density of wedgefd
      wedgefd.friction = 0.0f;///fixes the friction coefficient of wedgefd
      wedgefd.restitution = 0.0f;///fixes the coefficient of restitution of wedgefd
      b2BodyDef wedgebd;
      wedgebd.position.Set(29.5f, 28.0f);///sets the position of wedge
      sbody = m_world->CreateBody(&wedgebd);///creates the wedge
      sbody->CreateFixture(&wedgefd);///fixes the shape of wedge as defined
      
      //The plank on top of the wedge
      shape.SetAsBox(5.18f, 0.1f);
      b2BodyDef bd2;
      bd2.position.Set(29.5f, 29.5f);
      bd2.type = b2_dynamicBody;
      b2Body* body = m_world->CreateBody(&bd2);
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.f;
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;
      body->CreateFixture(fd2);

      b2RevoluteJointDef jd;
      b2Vec2 anchor;
      anchor.Set(29.5f,29.0f);
      jd.Initialize(sbody, body, anchor);
      m_world->CreateJoint(&jd);
      //box beside the see saw
      b2PolygonShape shape2;
      shape2.SetAsBox(1.0f,0.5f);
      b2BodyDef bd3;
      bd3.position.Set(35.6f, 28.5f);
      //bd3.type = b2_dynamicBody;
      b2Body* body3 = m_world->CreateBody(&bd3);
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 0.1f;
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;
      body3->CreateFixture(fd3);
     ///sphere on the box
     b2Body* spherebody;
  
      b2CircleShape circle;
      circle.m_radius = 1.0;
  
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 3.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(35.6f, 30.5f);
      spherebody = m_world->CreateBody(&ballbd);
      spherebody->CreateFixture(&ballfd);
      {
        b2PolygonShape shape;
        shape.SetAsBox(0.2f, 0.8f);
  
        b2BodyDef bd;
        bd.position.Set(22.5f, 28.4f);
        b2Body* ground = m_world->CreateBody(&bd);
        ground->CreateFixture(&shape, 0.0f);
      }
    } 
    {
     // horizontal shelf
      b2PolygonShape shape;
      shape.SetAsBox(7.0f, 0.1f);
  
      b2BodyDef bd;
      bd.position.Set(43.0f, 23.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
      //triangular wedge
      b2Body* sbody;
      b2PolygonShape poly;
      b2Vec2 vertices[3];
      vertices[0].Set(-1,0);///sets each of the vertices of wedge
      vertices[1].Set(1,0);///sets each of the vertices of wedge
      vertices[2].Set(0,1.5);///sets each of the vertices of wedge
      poly.Set(vertices, 3);
      b2FixtureDef wedgefd;
      wedgefd.shape = &poly;///fixes the shape of wedgefd
      wedgefd.density = 10.0f;///fixes the density of wedgefd
      wedgefd.friction = 0.0f;///fixes the friction coefficient of wedgefd
      wedgefd.restitution = 0.0f;///fixes the coefficient of restitution of wedgefd
      b2BodyDef wedgebd;
      wedgebd.position.Set(43.0f, 23.0f);///sets the position of wedge
      sbody = m_world->CreateBody(&wedgebd);///creates the wedge
      sbody->CreateFixture(&wedgefd);///fixes the shape of wedge as defined
      
      //The plank on top of the wedge
      shape.SetAsBox(5.18f, 0.1f);
      b2BodyDef bd2;
      bd2.position.Set(43.0f, 24.5f);
      bd2.type = b2_dynamicBody;
      b2Body* body = m_world->CreateBody(&bd2);
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.f;
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;
      body->CreateFixture(fd2);

      b2RevoluteJointDef jd;
      b2Vec2 anchor;
      anchor.Set(43.0f,24.0f);
      jd.Initialize(sbody, body, anchor);
      m_world->CreateJoint(&jd);
      //box beside the see saw
      b2PolygonShape shape2;
      shape2.SetAsBox(1.0f,0.5f);
      b2BodyDef bd3;
      bd3.position.Set(49.1f, 23.5f);
      //bd3.type = b2_dynamicBody;
      b2Body* body3 = m_world->CreateBody(&bd3);
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 0.1f;
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;
      body3->CreateFixture(fd3);
      ///sphere on the box
      b2Body* spherebody;
  
      b2CircleShape circle;
      circle.m_radius = 1.0;
  
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 3.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(49.1f, 25.5f);
      spherebody = m_world->CreateBody(&ballbd);
      spherebody->CreateFixture(&ballfd);   
      {
        b2PolygonShape shape;
        shape.SetAsBox(0.2f, 0.8f);
  
        b2BodyDef bd;
        bd.position.Set(36.0f, 23.4f);
        b2Body* ground = m_world->CreateBody(&bd);
        ground->CreateFixture(&shape, 0.0f);
      } 
    }
    {
     // horizontal shelf
      b2PolygonShape shape;
      shape.SetAsBox(7.0f, 0.1f);
  
      b2BodyDef bd;
      bd.position.Set(56.5f, 18.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
      //triangular wedge
      b2Body* sbody;
      b2PolygonShape poly;
      b2Vec2 vertices[3];
      vertices[0].Set(-1,0);///sets each of the vertices of wedge
      vertices[1].Set(1,0);///sets each of the vertices of wedge
      vertices[2].Set(0,1.5);///sets each of the vertices of wedge
      poly.Set(vertices, 3);
      b2FixtureDef wedgefd;
      wedgefd.shape = &poly;///fixes the shape of wedgefd
      wedgefd.density = 10.0f;///fixes the density of wedgefd
      wedgefd.friction = 0.0f;///fixes the friction coefficient of wedgefd
      wedgefd.restitution = 0.0f;///fixes the coefficient of restitution of wedgefd
      b2BodyDef wedgebd;
      wedgebd.position.Set(56.5f, 18.0f);///sets the position of wedge
      sbody = m_world->CreateBody(&wedgebd);///creates the wedge
      sbody->CreateFixture(&wedgefd);///fixes the shape of wedge as defined
      
      //The plank on top of the wedge
      shape.SetAsBox(5.18f, 0.1f);
      b2BodyDef bd2;
      bd2.position.Set(56.5f, 19.5f);
      bd2.type = b2_dynamicBody;
      b2Body* body = m_world->CreateBody(&bd2);
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.f;
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;
      body->CreateFixture(fd2);

      b2RevoluteJointDef jd;
      b2Vec2 anchor;
      anchor.Set(56.5f,19.0f);
      jd.Initialize(sbody, body, anchor);
      m_world->CreateJoint(&jd);
      //box beside the see saw
      b2PolygonShape shape2;
      shape2.SetAsBox(1.0f,0.5f);
      b2BodyDef bd3;
      bd3.position.Set(62.6f, 18.5f);
      //bd3.type = b2_dynamicBody;
      b2Body* body3 = m_world->CreateBody(&bd3);
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 0.1f;
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;
      body3->CreateFixture(fd3);
     ///sphere on the box
     b2Body* spherebody;
  
      b2CircleShape circle;
      circle.m_radius = 1.0;
  
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 3.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(62.6f, 20.5f);
      spherebody = m_world->CreateBody(&ballbd);
      spherebody->CreateFixture(&ballfd);

      {
        b2PolygonShape shape;
        shape.SetAsBox(0.2f, 0.8f);
  
        b2BodyDef bd;
        bd.position.Set(49.9f, 18.4f);
        b2Body* ground = m_world->CreateBody(&bd);
        ground->CreateFixture(&shape, 0.0f);
      } 
    }
 }

//dominos on ground     
   {
      b2PolygonShape shape;
      shape.SetAsBox(0.1f, 7.0f);
  
      b2FixtureDef fd;
      fd.shape = &shape;
      fd.density = 20.0f;
      fd.friction = 0.1f;
    
      for (int i = 0; i < 3; ++i)
       {
         b2BodyDef bd;
         bd.type = b2_dynamicBody;
         bd.position.Set(-8.0f + 8.0f * i, 7.0f);
        b2Body* body = m_world->CreateBody(&bd);
        body->CreateFixture(&fd);
       } 
    }
 //revolving platform with balls    
   {
        b2Body* b2;
        {
          b2PolygonShape shape;
          shape.SetAsBox(0.01f, 0.01f);
          b2BodyDef bd;
          bd.position.Set(4.f, 10.01f);
          b2 = m_world->CreateBody(&bd);
          b2->CreateFixture(&shape, 10.0f);
        }
        b2Body* b4;
        {
          b2PolygonShape shape;
          shape.SetAsBox(3.0f, 0.1f);
          b2BodyDef bd;
          bd.type = b2_dynamicBody;
          bd.position.Set(4.f, 10.0f);
          b4 = m_world->CreateBody(&bd);
          b4->CreateFixture(&shape, 2.0f);
        }
        b2RevoluteJointDef jd;
        b2Vec2 anchor;
        anchor.Set(4.f, 10.0f);
        jd.Initialize(b2, b4, anchor);
        m_world->CreateJoint(&jd);
        {
          b2Body* spherebody;  
          b2CircleShape circle;
          circle.m_radius = 0.5;
          b2FixtureDef ballfd;
          ballfd.shape = &circle;
          ballfd.density = 0.5f;
          ballfd.friction = 0.0f;
          ballfd.restitution = 0.0f;
          b2BodyDef ballbd;
          ballbd.type = b2_dynamicBody;
          ballbd.position.Set(2.0f, 10.5f);
          spherebody = m_world->CreateBody(&ballbd);
          spherebody->CreateFixture(&ballfd);
        }
        {
          b2Body* spherebody;
          b2CircleShape circle;
          circle.m_radius = 0.5;
          b2FixtureDef ballfd;
          ballfd.shape = &circle;
          ballfd.density = 0.5f;
          ballfd.friction = 0.0f;
          ballfd.restitution = 0.0f;
          b2BodyDef ballbd;
          ballbd.type = b2_dynamicBody;
          ballbd.position.Set(6.0f, 10.5f);
          spherebody = m_world->CreateBody(&ballbd);
          spherebody->CreateFixture(&ballfd);
        }
   }
   {
        b2Body* b2;
        {
          b2PolygonShape shape;
          shape.SetAsBox(0.01f, 0.01f);
          b2BodyDef bd;
          bd.position.Set(-4.f, 10.01f);
          b2 = m_world->CreateBody(&bd);
          b2->CreateFixture(&shape, 10.0f);
        }
        b2Body* b4;
        {
          b2PolygonShape shape;
          shape.SetAsBox(3.0f, 0.1f);
          b2BodyDef bd;
          bd.type = b2_dynamicBody;
          bd.position.Set(-4.f, 10.0f);
          b4 = m_world->CreateBody(&bd);
          b4->CreateFixture(&shape, 2.0f);
        }
        b2RevoluteJointDef jd;
        b2Vec2 anchor;
        anchor.Set(-4.f, 10.0f);
        jd.Initialize(b2, b4, anchor);
        m_world->CreateJoint(&jd);
        {
          b2Body* spherebody;  
          b2CircleShape circle;
          circle.m_radius = 0.5;
          b2FixtureDef ballfd;
          ballfd.shape = &circle;
          ballfd.density = 1.0f;
          ballfd.friction = 0.0f;
          ballfd.restitution = 0.0f;
          b2BodyDef ballbd;
          ballbd.type = b2_dynamicBody;
          ballbd.position.Set(-6.0f, 10.5f);
          spherebody = m_world->CreateBody(&ballbd);
          spherebody->CreateFixture(&ballfd);
        }
        {
          b2Body* spherebody;
          b2CircleShape circle;
          circle.m_radius = 0.5;
          b2FixtureDef ballfd;
          ballfd.shape = &circle;
          ballfd.density = 1.0f;
          ballfd.friction = 0.0f;
          ballfd.restitution = 0.0f;
          b2BodyDef ballbd;
          ballbd.type = b2_dynamicBody;
          ballbd.position.Set(-2.0f, 10.5f);
          spherebody = m_world->CreateBody(&ballbd);
          spherebody->CreateFixture(&ballfd);
        }
   }        
  }
    }
  sim_t *sim = new sim_t("Dominos", dominos_t::create);
}