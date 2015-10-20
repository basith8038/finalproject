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
    //Ground
    /*! \var g1,g2,g3,g4,g5
     * \brief pointers to the body ground
     */
    {
       b2Body* g1;
        {
          b2EdgeShape shape;
          shape.Set(b2Vec2(30.0f, 0.0f), b2Vec2(200.0f, 0.0f));
          b2BodyDef bd;
          g1 = m_world->CreateBody(&bd);
          g1->CreateFixture(&shape, 0.0f);
        }   
        b2Body* g2;
        {
          b2EdgeShape shape;
          shape.Set(b2Vec2(-90.0f, 0.0f), b2Vec2(10.0f, 0.0f));
          b2BodyDef bd;
          g2 = m_world->CreateBody(&bd);
          g2->CreateFixture(&shape, 0.0f);
        } 
        b2Body* g3;
        {
          b2EdgeShape shape;
          shape.Set(b2Vec2(10.0f, -5.0f), b2Vec2(30.0f, -5.0f));
          b2BodyDef bd;
          g3 = m_world->CreateBody(&bd);
          g3->CreateFixture(&shape, 0.0f);
        }
        b2Body* g4;
        {
          b2EdgeShape shape;
          shape.Set(b2Vec2(10.0f, 0.0f), b2Vec2(10.0f, -5.0f));
          b2BodyDef bd;
          g4 = m_world->CreateBody(&bd);
          g4->CreateFixture(&shape, 0.0f);
        }
        b2Body* g5;
        {
          b2EdgeShape shape;
          shape.Set(b2Vec2(30.0f, 0.0f), b2Vec2(30.0f, -5.0f));
          b2BodyDef bd;
          g5 = m_world->CreateBody(&bd);
          g5->CreateFixture(&shape, 0.0f);
        }
    }

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
      ballbd.position.Set(-37.5f, 20.5f);
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
  //The middle pulley system
        /** \brief THIS BLOCK CREATES THE ENTIRE MIDDLE PULLEY SYSTEM  ALONG WITH ITS COMPONENTS*/
    {
      {
      b2Body* sbody;
      b2CircleShape circle;
      circle.m_radius = 0.75;

      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 50.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_staticBody;
      ballbd.position.Set(15.f, 40.f);
      sbody = m_world->CreateBody(&ballbd);
      sbody->CreateFixture(&ballfd);
      }
      {
      b2Body* sbody;
      b2CircleShape circle;
      circle.m_radius = 0.75;

      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 50.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_staticBody;
      ballbd.position.Set(25.f, 40.f);
      sbody = m_world->CreateBody(&ballbd);
      sbody->CreateFixture(&ballfd);
      }
      {
      //the two boxes of middle pulley
      b2PolygonShape shape;
      shape.SetAsBox(1.0f, 1.0f);
      b2BodyDef bd1;
      b2BodyDef bd2;
      bd1.position.Set(15.0f, 35.0f);
      bd1.type = b2_dynamicBody;
      bd2.position.Set(25.0f, 35.0f);
      bd2.type = b2_dynamicBody;
      b2Body* body1 = m_world->CreateBody(&bd1);
      b2Body* body2 = m_world->CreateBody(&bd2);
      b2FixtureDef *fd = new b2FixtureDef;
      fd->density = 10.f;
      fd->shape = new b2PolygonShape;
      fd->shape = &shape;
      body1->CreateFixture(fd);
      body2->CreateFixture(fd);
      //the middle joint for pulley
      b2Body* sbody;
      b2CircleShape circle;
      circle.m_radius = 0.05;
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 30.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(20.f, 30.f);
      sbody = m_world->CreateBody(&ballbd);
      sbody->CreateFixture(&ballfd);
      // The pulley joint left half
      b2PulleyJointDef* myjoint1 = new b2PulleyJointDef();
      b2Vec2 worldAnchorOnBody11(15, 35.5); // Anchor point on body 1 in world axis
      b2Vec2 worldAnchorOnBody12(20, 30); // Anchor point on body 2 in world axis
      b2Vec2 worldAnchorGround11(15, 40); // Anchor point for ground 1 in world axis
      b2Vec2 worldAnchorGround12(15, 40); // Anchor point for ground 2 in world axis
      float32 ratio1 = 1.0f; // Define ratio
      myjoint1->Initialize(body1, sbody, worldAnchorGround11, worldAnchorGround12, body1->GetWorldCenter(), sbody->GetWorldCenter(), ratio1);
      m_world->CreateJoint(myjoint1);
      // The pulley joint right half
      b2PulleyJointDef* myjoint2 = new b2PulleyJointDef();
      b2Vec2 worldAnchorOnBody21(25, 35.5); // Anchor point on body 1 in world axis
      b2Vec2 worldAnchorOnBody22(20, 30); // Anchor point on body 2 in world axis
      b2Vec2 worldAnchorGround21(25, 40); // Anchor point for ground 1 in world axis
      b2Vec2 worldAnchorGround22(25, 40); // Anchor point for ground 2 in world axis
      float32 ratio2 = 1.0f; // Define ratio
      myjoint2->Initialize(body2, sbody, worldAnchorGround21, worldAnchorGround22, body2->GetWorldCenter(), sbody->GetWorldCenter(), ratio2);
      m_world->CreateJoint(myjoint2);
      //bottom joint for pan
      b2Body* sbody2;
      b2CircleShape circle2;
      circle2.m_radius = 0.05;
      b2FixtureDef ballfd2;
      ballfd2.shape = &circle2;
      ballfd2.density = 30.0f;
      ballfd2.friction = 0.0f;
      ballfd2.restitution = 0.0f;
      b2BodyDef ballbd2;
      ballbd2.type = b2_dynamicBody;
      ballbd2.position.Set(20.f, 10.f);
      sbody2 = m_world->CreateBody(&ballbd2);
      sbody2->CreateFixture(&ballfd2);
      //thread connecting two joints
      b2DistanceJointDef jointDef;
      b2Vec2 worldAnchorOnBodyA(20, 30); // Anchor point on body A in world axis
      b2Vec2 worldAnchorOnBodyB(20, 10); // Anchor point on body B in world axis
      jointDef.Initialize(sbody, sbody2, worldAnchorOnBodyA, worldAnchorOnBodyB);
      jointDef.collideConnected = false;
      jointDef.frequencyHz = 0.0f;
      jointDef.dampingRatio = 1.f;
      m_world->CreateJoint(&jointDef);
      //open box at bottom of pulley
      b2BodyDef *bd = new b2BodyDef;
      bd->type = b2_dynamicBody;
      bd->position.Set(20,-3);
      bd->fixedRotation = true;
      b2FixtureDef *fd1 = new b2FixtureDef;
      fd1->density = 10.0;
      fd1->friction = 0.5;
      fd1->restitution = 0.f;
      fd1->shape = new b2PolygonShape;
      b2PolygonShape bs1;
      bs1.SetAsBox(4,0.2, b2Vec2(0.f,-1.9f), 0);
      fd1->shape = &bs1;
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.0;
      fd2->friction = 0.5;
      fd2->restitution = 0.f;
      fd2->shape = new b2PolygonShape;
      b2PolygonShape bs2;
      bs2.SetAsBox(0.2,1, b2Vec2(4.0f,-1.f), 0);
      fd2->shape = &bs2;
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 10.0;
      fd3->friction = 0.5;
      fd3->restitution = 0.f;
      fd3->shape = new b2PolygonShape;
      b2PolygonShape bs3;
      bs3.SetAsBox(0.2,1, b2Vec2(-4.0f,-1.f), 0);
      fd3->shape = &bs3;
      b2Body* box1 = m_world->CreateBody(bd);
      box1->CreateFixture(fd1);
      box1->CreateFixture(fd2);
      box1->CreateFixture(fd3);
      //threads connecting 2nd joint and openbox
      b2DistanceJointDef jointDef1;
      b2DistanceJointDef jointDef2;
      b2Vec2 worldAnchorOnBodyA1(20, 10); // Anchor point on body A in world axis
      b2Vec2 worldAnchorOnBodyB1(16, -3); // Anchor point on body B in world axis
      b2Vec2 worldAnchorOnBodyA2(20, 10); // Anchor point on body A in world axis
      b2Vec2 worldAnchorOnBodyB2(24, -3); // Anchor point on body B in world axis
      jointDef1.Initialize(sbody2, box1, worldAnchorOnBodyA1, worldAnchorOnBodyB1);
      jointDef2.Initialize(sbody2, box1, worldAnchorOnBodyA2, worldAnchorOnBodyB2);
      jointDef1.collideConnected = false;
      jointDef1.frequencyHz = 0.0f;
      jointDef1.dampingRatio = 1.f;
      m_world->CreateJoint(&jointDef1);
      jointDef2.collideConnected = false;
      jointDef2.frequencyHz = 0.0f;
      jointDef2.dampingRatio = 1.f;
      m_world->CreateJoint(&jointDef2);
      }
    }
   //horizontal shelf,seesaw with dominos on it
           /** \brief THIS BLOCK CREATES HORIZONTAL SHELF,SEESAW WITH DOMINOS ON BOTH SIDES OF IT */
    {
     // horizontal shelf
      b2PolygonShape shape;
      shape.SetAsBox(11.0f, 0.2f);
  
      b2BodyDef bd;
      bd.position.Set(70.5f, 9.9f);
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
      wedgebd.position.Set(70.5f, 10.0f);///sets the position of wedge
      sbody = m_world->CreateBody(&wedgebd);///creates the wedge
      sbody->CreateFixture(&wedgefd);///fixes the shape of wedge as defined
      
      //The plank on top of the wedge
      shape.SetAsBox(6.0f, 0.1f);
      b2BodyDef bd2;
      bd2.position.Set(70.5f, 11.5f);
      bd2.type = b2_dynamicBody;
      b2Body* body = m_world->CreateBody(&bd2);
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.f;
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;
      body->CreateFixture(fd2);

      b2RevoluteJointDef jd;
      b2Vec2 anchor;
      anchor.Set(70.5f,11.0f);
      jd.Initialize(sbody, body, anchor);
      m_world->CreateJoint(&jd);
     /* //boxes on seesaw
      b2PolygonShape shape2;
      shape2.SetAsBox(1.0f,1.0f);
      b2BodyDef bd3;
      bd3.type = b2_dynamicBody;
      b2BodyDef bd4;
      bd4.type = b2_dynamicBody;
      bd3.position.Set(66.5f, 12.5f);
      bd4.position.Set(74.5f, 12.5f);
      //bd3.type = b2_dynamicBody;
      b2Body* body3 = m_world->CreateBody(&bd3);
      b2Body* body4 = m_world->CreateBody(&bd4);
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 0.01f;
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;
      body3->CreateFixture(fd3);
      body4->CreateFixture(fd3); */
     {
      b2PolygonShape shape;
      shape.SetAsBox(0.1f, 6.6f);
  
      b2FixtureDef fd;
      fd.shape = &shape;
      fd.density = 0.01f;
      fd.friction = 0.1f;
    
     // for (int i = 0; i < 11; ++i)
       {
         b2BodyDef bd;
         bd.type = b2_dynamicBody;
         bd.position.Set(76.0f,19.0f);
        b2Body* body = m_world->CreateBody(&bd);
        body->CreateFixture(&fd);
       } 
       {
         b2BodyDef bd;
         bd.type = b2_dynamicBody;
         bd.position.Set(65.0f,19.0f);
        b2Body* body = m_world->CreateBody(&bd);
        body->CreateFixture(&fd);
       } 
      } 
       {
        b2PolygonShape shape;
        shape.SetAsBox(0.2f, 0.8f);
  
        b2BodyDef bd;
        bd.position.Set(59.5f, 10.3f);
        b2Body* ground = m_world->CreateBody(&bd);
        ground->CreateFixture(&shape, 0.0f);
      } 
      {
        b2PolygonShape shape;
        shape.SetAsBox(0.2f, 0.8f);
  
        b2BodyDef bd;
        bd.position.Set(81.5f, 10.3f);
        b2Body* ground = m_world->CreateBody(&bd);
        ground->CreateFixture(&shape, 0.0f);
      }         
    }

//The right pulley system
            /** \brief THIS BLOCK CREATES THE ENTIRE RIGHT  PULLEY SYSTEM  ALONG WITH ITS COMPONENTS*/
    {
      b2BodyDef *bd = new b2BodyDef;
      bd->type = b2_dynamicBody;
      bd->position.Set(112,2);//changed
      bd->fixedRotation = true;

      //The closed box
      b2FixtureDef *fd1 = new b2FixtureDef;
      fd1->density = 10.0;
      fd1->friction = 0.5;
      fd1->restitution = 0.f;
      fd1->shape = new b2PolygonShape;
      b2PolygonShape bs1;
      bs1.SetAsBox(1.5, 0.2, b2Vec2(0.f,-1.4f), 0);
      fd1->shape = &bs1;
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.0;
      fd2->friction = 0.5;
      fd2->restitution = 0.f;
      fd2->shape = new b2PolygonShape;
      b2PolygonShape bs2;
      bs2.SetAsBox(0.2, 1.5, b2Vec2(1.5f,0.f), 0);
      fd2->shape = &bs2;
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 10.0;
      fd3->friction = 0.5;
      fd3->restitution = 0.f;
      fd3->shape = new b2PolygonShape;
      b2PolygonShape bs3;
      bs3.SetAsBox(0.2, 1.5, b2Vec2(-1.5f,0.f), 0);
      fd3->shape = &bs3;
      b2FixtureDef *fd4 = new b2FixtureDef;
      fd4->density = 10.0;
      fd4->friction = 0.5;
      fd4->restitution = 0.f;
      fd4->shape = new b2PolygonShape;
      b2PolygonShape bs4;
      bs4.SetAsBox(1.5, 0.2, b2Vec2(0.f,1.4f), 0);
      fd4->shape = &bs4;

      b2Body* box1 = m_world->CreateBody(bd);
      box1->CreateFixture(fd1);
      box1->CreateFixture(fd2);
      box1->CreateFixture(fd3);
      box1->CreateFixture(fd4);

      //The bar
      bd->position.Set(92,20);
      fd1->density = 40.15;//fd1->density = 34.0;
      b2Body* box2 = m_world->CreateBody(bd);
      box2->CreateFixture(fd1);

      // The pulley joint
      b2PulleyJointDef* myjoint = new b2PulleyJointDef();
      b2Vec2 worldAnchorOnBody1(112, 2); // Anchor point on body 1 in world axis
      b2Vec2 worldAnchorOnBody2(92, 20); // Anchor point on body 2 in world axis
      b2Vec2 worldAnchorGround1(112, 37); // Anchor point for ground 1 in world axis
      b2Vec2 worldAnchorGround2(92, 37); // Anchor point for ground 2 in world axis
      float32 ratio = 1.0f; // Define ratio
      myjoint->Initialize(box1, box2, worldAnchorGround1, worldAnchorGround2, box1->GetWorldCenter(), box2->GetWorldCenter(), ratio);
      m_world->CreateJoint(myjoint);
    }
     //rod fixed with ball on it
    {
     
      {
          b2Body* b2;
          {
          b2PolygonShape shape;
          shape.SetAsBox(2.25f, 0.2f);
          b2BodyDef bd;
          bd.position.Set(83.0f, 30.0f);
          b2 = m_world->CreateBody(&bd);
          b2->CreateFixture(&shape, 10.0f);
        }
          b2Body* b4;
          {
          b2PolygonShape shape;
          shape.SetAsBox(7.5f, 0.2f);    
          b2BodyDef bd;
          bd.type = b2_dynamicBody;
          bd.position.Set(83.0f, 26.0f);
          b4 = m_world->CreateBody(&bd);
          b4->CreateFixture(&shape, 2.0f);
        }  
        b2RevoluteJointDef jd;
        b2Vec2 anchor;
        anchor.Set(83.0f, 30.0f);
        jd.Initialize(b2, b4, anchor);
        m_world->CreateJoint(&jd);
      }     
      {
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
        ballbd.position.Set(89.0f, 27.5f);
        spherebody = m_world->CreateBody(&ballbd);
        spherebody->CreateFixture(&ballfd);
      }
      {
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
        ballbd.position.Set(77.0f, 27.5f);
        spherebody = m_world->CreateBody(&ballbd);
        spherebody->CreateFixture(&ballfd);
      }
    }
        //The revolving horizontal platform
              /** \brief THIS BLOCK CREATES HORIZONTAL PLATFORM WITH BALLS ON IT*/
    {
        b2Body* b2;
        {
          b2PolygonShape shape;
          shape.SetAsBox(0.01f, 0.01f);
          b2BodyDef bd;
          bd.position.Set(108.f, 12.01f);
          b2 = m_world->CreateBody(&bd);
          b2->CreateFixture(&shape, 10.0f);
        }
        b2Body* b4;
        {
          b2PolygonShape shape;
          shape.SetAsBox(3.0f, 0.1f);
          b2BodyDef bd;
          bd.type = b2_dynamicBody;
          bd.position.Set(108.f, 12.0f);
          b4 = m_world->CreateBody(&bd);
          b4->CreateFixture(&shape, 2.0f);
        }
        b2RevoluteJointDef jd;
        b2Vec2 anchor;
        anchor.Set(108.f, 12.0f);
        jd.Initialize(b2, b4, anchor);
        m_world->CreateJoint(&jd);
        {
          b2Body* spherebody;  
          b2CircleShape circle;
          circle.m_radius = 0.5;
          b2FixtureDef ballfd;
          ballfd.shape = &circle;
          ballfd.density = 20.0f;
          ballfd.friction = 0.0f;
          ballfd.restitution = 0.0f;
          b2BodyDef ballbd;
          ballbd.type = b2_dynamicBody;
          ballbd.position.Set(106.0f, 12.5f);
          spherebody = m_world->CreateBody(&ballbd);
          spherebody->CreateFixture(&ballfd);
        }
        {
          b2Body* spherebody;
          b2CircleShape circle;
          circle.m_radius = 0.5;
          b2FixtureDef ballfd;
          ballfd.shape = &circle;
          ballfd.density = 20.0f;
          ballfd.friction = 0.0f;
          ballfd.restitution = 0.0f;
          b2BodyDef ballbd;
          ballbd.type = b2_dynamicBody;
          ballbd.position.Set(110.0f, 12.5f);
          spherebody = m_world->CreateBody(&ballbd);
          spherebody->CreateFixture(&ballfd);
        }
    }
    // horizontal,vertical shelf
                  /** \brief THIS BLOCK CREATES HORIZONTAL,VERTICAL SHELFES TO HOLD FALLING BALL,PLATFORM*/
    {
      
      {
      b2PolygonShape shape;
      shape.SetAsBox(4.0f, 0.2f);
  
      b2BodyDef bd;
      bd.position.Set(92.5f, 7.9f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
     }

      {
      b2PolygonShape shape;
      shape.SetAsBox(0.2f, 0.5f);
  
      b2BodyDef bd;
      bd.position.Set(88.5f, 8.1f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
     }
      {
      b2PolygonShape shape;
      shape.SetAsBox(0.2f, 0.5f);
  
      b2BodyDef bd;
      bd.position.Set(96.5f, 8.1f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
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
    
      for (int i = 0; i < 2; ++i)
       {
         b2BodyDef bd;
         bd.type = b2_dynamicBody;
         bd.position.Set(0.0f + 8.0f * i, 7.0f);
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
          ballfd.density = 0.5f;
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
          ballfd.density = 0.5f;
          ballfd.friction = 0.0f;
          ballfd.restitution = 0.0f;
          b2BodyDef ballbd;
          ballbd.type = b2_dynamicBody;
          ballbd.position.Set(-2.0f, 10.5f);
          spherebody = m_world->CreateBody(&ballbd);
          spherebody->CreateFixture(&ballfd);
        }
   }        
   //dominos on ground     
   {
      b2PolygonShape shape;
      shape.SetAsBox(0.1f, 7.0f);
  
      b2FixtureDef fd;
      fd.shape = &shape;
      fd.density = 20.0f;
      fd.friction = 0.0f;
    
      for (int i = 0; i < 2; ++i)
       {
         b2BodyDef bd;
         bd.type = b2_dynamicBody;
         bd.position.Set(32.0f + 8.0f * i, 7.0f);
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
          bd.position.Set(46.f, 8.01f);
          b2 = m_world->CreateBody(&bd);
          b2->CreateFixture(&shape, 10.0f);
        }
        b2Body* b4;
        {
          b2PolygonShape shape;
          shape.SetAsBox(3.0f, 0.1f);
          b2BodyDef bd;
          bd.type = b2_dynamicBody;
          bd.position.Set(46.f, 8.0f);
          b4 = m_world->CreateBody(&bd);
          b4->CreateFixture(&shape, 2.0f);
        }
        b2RevoluteJointDef jd;
        b2Vec2 anchor;
        anchor.Set(46.f, 8.0f);
        jd.Initialize(b2, b4, anchor);
        m_world->CreateJoint(&jd);
        {
          b2Body* spherebody;  
          b2CircleShape circle;
          circle.m_radius = 0.5;
          b2FixtureDef ballfd;
          ballfd.shape = &circle;
          ballfd.density = 0.7f;
          ballfd.friction = 0.0f;
          ballfd.restitution = 0.0f;
          b2BodyDef ballbd;
          ballbd.type = b2_dynamicBody;
          ballbd.position.Set(44.0f, 8.5f);
          spherebody = m_world->CreateBody(&ballbd);
          spherebody->CreateFixture(&ballfd);
        }
        {
          b2Body* spherebody;
          b2CircleShape circle;
          circle.m_radius = 0.5;
          b2FixtureDef ballfd;
          ballfd.shape = &circle;
          ballfd.density = 0.7f;
          ballfd.friction = 0.0f;
          ballfd.restitution = 0.0f;
          b2BodyDef ballbd;
          ballbd.type = b2_dynamicBody;
          ballbd.position.Set(48.0f, 8.5f);
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
          bd.position.Set(36.f, 10.01f);
          b2 = m_world->CreateBody(&bd);
          b2->CreateFixture(&shape, 10.0f);
        }
        b2Body* b4;
        {
          b2PolygonShape shape;
          shape.SetAsBox(3.0f, 0.1f);
          b2BodyDef bd;
          bd.type = b2_dynamicBody;
          bd.position.Set(36.f, 10.0f);
          b4 = m_world->CreateBody(&bd);
          b4->CreateFixture(&shape, 2.0f);
        }
        b2RevoluteJointDef jd;
        b2Vec2 anchor;
        anchor.Set(36.f, 10.0f);
        jd.Initialize(b2, b4, anchor);
        m_world->CreateJoint(&jd);
        {
          b2Body* spherebody;  
          b2CircleShape circle;
          circle.m_radius = 0.5;
          b2FixtureDef ballfd;
          ballfd.shape = &circle;
          ballfd.density = 0.30f;
          ballfd.friction = 0.0f;
          ballfd.restitution = 0.0f;
          b2BodyDef ballbd;
          ballbd.type = b2_dynamicBody;
          ballbd.position.Set(34.0f, 10.5f);
          spherebody = m_world->CreateBody(&ballbd);
          spherebody->CreateFixture(&ballfd);
        }
        {
          b2Body* spherebody;
          b2CircleShape circle;
          circle.m_radius = 0.5;
          b2FixtureDef ballfd;
          ballfd.shape = &circle;
          ballfd.density = 0.30f;
          ballfd.friction = 0.0f;
          ballfd.restitution = 0.0f;
          b2BodyDef ballbd;
          ballbd.type = b2_dynamicBody;
          ballbd.position.Set(38.0f, 10.5f);
          spherebody = m_world->CreateBody(&ballbd);
          spherebody->CreateFixture(&ballfd);
        }
   }        
  


  }
  sim_t *sim = new sim_t("Dominos", dominos_t::create);
}
