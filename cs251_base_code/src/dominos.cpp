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
    {//a part of the Ground
       b2Body* g1;
        {//a part of the Ground
          b2EdgeShape shape;/// shape of type b2EdgeShape which is a line segment 
          shape.Set(b2Vec2(30.0f, 0.0f), b2Vec2(150.0f, 0.0f));/// sets the shape between the points given 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          g1 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          g1->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined
        } 
      //a part of the Ground    
        b2Body* g2;
        {
          b2EdgeShape shape;/// shape of type b2EdgeShape which is a line segment 
          shape.Set(b2Vec2(-90.0f, 0.0f), b2Vec2(10.0f, 0.0f));;/// sets the shape between the points given 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          g2 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          g2->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined
        }
      //a part of the Ground       
        b2Body* g3;
        {
          b2EdgeShape shape;/// shape of type b2EdgeShape which is a line segment 
          shape.Set(b2Vec2(10.0f, -5.0f), b2Vec2(30.0f, -5.0f));;/// sets the shape between the points given 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          g3 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          g3->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined
        }
      //a part of the Ground      
        b2Body* g4;
        {
          b2EdgeShape shape;/// shape of type b2EdgeShape which is a line segment 
          shape.Set(b2Vec2(10.0f, 0.0f), b2Vec2(10.0f, -5.0f));;/// sets the shape between the points given 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          g4 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          g4->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined
        }
      //a part of the Ground      
        b2Body* g5;
        {
          b2EdgeShape shape;/// shape of type b2EdgeShape which is a line segment 
          shape.Set(b2Vec2(30.0f, 0.0f), b2Vec2(30.0f, -5.0f));;/// sets the shape between the points given 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          g5 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          g5->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined
        }
    }

    //Top horizontal shelf
        /** \brief THIS BLOCK CREATES TOP HORIZONTAL SHELF  TO HOLD DOMINOS*/
  { 
    
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(8.0f, 0.25f);///< SetAsBox sets the dimensions of box(shape) 
	
      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(-33.0f, 20.0f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f); /// CreateFixture fixes the shape of body as defined   
  }
    //another horizontal shelf
          /** \brief THIS BLOCK CREATES HORIZONTAL SHELF NEXT TO INCLINED PLANE*/
  {
    
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(5.0f, 0.25f);///< SetAsBox sets the dimensions of box(shape) 
  
      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(-11.0f, 19.75f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);   /// CreateFixture fixes the shape of body as defined   
  }
    //inclined plane
              /** \brief THIS BLOCK CREATES INCLINED PLANENEXT TO HORIZONTAL SHELF*/
  {
    
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(6.0f, 0.25f, b2Vec2(0.f,0.f), 7.0f);///< SetAsBox sets the dimensions of box(shape) 
      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(-1.5f, 23.75f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f); /// CreateFixture fixes the shape of body  as defined     
  }  
    //Dominos
        /** \brief THIS BLOCK CREATES DOMINOES ON TOP HORIZONTAL SHELF */
  {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(0.1f, 1.0f);///< SetAsBox sets the dimensions of box(shape) 
	
      b2FixtureDef fd; /// fd is variable of type b2FixtureDef
                       /// maintains properties of body
      fd.shape = &shape; /// fixes the shape of body as defined
      fd.density = 20.0f; /// fixes density of body
      fd.friction = 0.1f; /// fixing friction coefficient of body
    
		
      for (int i = 0; i < 11; ++i)
	     {
	       b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
	       bd.type = b2_dynamicBody;/// Sets the type of body to be created
	       bd.position.Set(-35.65f + 1.0f * i, 21.25f);/// Sets the position of body to be created
    	  b2Body* body = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
    	  body->CreateFixture(&fd);/// CreateFixture fixes the shape of body as defined   
	     } 
  }

      // horizontal,vertical shelf near domino
            /** \brief THIS BLOCK CREATES HORIZONTAL,VERTICAL SHELFES TO HOLD FALLING BALL,DOMINO*/
  {
      {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(3.0f, 0.2f);///< SetAsBox sets the dimensions of box(shape) 
  
      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(-21.0f, 17.0f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined   
      }
      {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(0.2f, 0.5f);///< SetAsBox sets the dimensions of box(shape) 
  
      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(-24.0f, 17.2f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined   
      }
      {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(0.2f, 0.5f);///< SetAsBox sets the dimensions of box(shape) 
  
      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(-18.0f, 17.2f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined   
      }
  }
          //Inclined planes
      /** \brief THIS BLOCK CREATES THE BIGGER INCLINED PLANES BELOW DOMINOS SHELF */   
  {
    {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(6.0f, 0.25f, b2Vec2(0.f,0.f), 6.0f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(-40.0f, 15.5f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined   
    }
    {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(6.0f, 0.25f, b2Vec2(0.f,0.f), -6.0f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(-32.0f, 10.5f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined   
    }
    {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(6.0f, 0.25f, b2Vec2(0.f,0.f), 6.0f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(-40.0f, 5.5f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined   
    }
  }
    //small inclined planes
      /** \brief THIS BLOCK CREATES THE SMALLER INCLINED PLANES BELOW DOMINOS SHELF */   
  {
    {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(1.0f, 0.25f, b2Vec2(0.f,0.f), 7.0f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(-45.0f, 18.0f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined  
    }
    {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(1.0f, 0.25f, b2Vec2(0.f,0.f), -7.0f);///< SetAsBox sets the dimensions of box(shape)

      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(-27.0f, 13.0f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined  
    }
    {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(1.0f, 0.25f, b2Vec2(0.f,0.f), 7.0f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(-45.0f, 8.0f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined  
    }
  }
    //horizontal pendulums
        /** \brief THIS BLOCK CREATES PENNDULUMS TO KNOCK THE DOMINOS*/
  {
    {
        b2Body* b2;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.25f, 0.25f);///< SetAsBox sets the dimensions of box(shape) 

          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.position.Set(-24.5f, 30.0f);/// Sets the position of body to be created
          b2 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          b2->CreateFixture(&shape, 10.0f);/// CreateFixture fixes the shape of body as defined  
        }    
        b2Body* b4;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.5f, 0.5f);///< SetAsBox sets the dimensions of box(shape) 

          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.type = b2_dynamicBody;/// Sets the type of body to be created
          bd.position.Set(-24.5f, 21.0f);/// Sets the position of body to be created
          b4 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          b4->CreateFixture(&shape, 2.0f);/// CreateFixture fixes the shape of body as defined  
        }
    
        b2RevoluteJointDef jd;///a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
        b2Vec2 anchor;/// a point. (type - b2Vec2) 
        anchor.Set(-24.5f, 30.0f);///function which sets coordinates of anchor to (-37.0, 40.0). 
        jd.Initialize(b2, b4, anchor);///jd is then initialized as a revolute joint joining \b b2 and \b b4 by \b anchor, then created in the world. 
        m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
    }
    {
        b2Body* b2;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.25f, 0.25f);///< SetAsBox sets the dimensions of box(shape) 

          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.position.Set(-22.5f, 30.0f);/// Sets the position of body to be created
          b2 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          b2->CreateFixture(&shape, 10.0f);/// CreateFixture fixes the shape of body as defined  
        } 
        b2Body* b4;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.5f, 0.5f);///< SetAsBox sets the dimensions of box(shape) 

          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.type = b2_dynamicBody;/// Sets the type of body to be created
          bd.position.Set(-22.5f, 21.0f);/// Sets the position of body to be created
          b4 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          b4->CreateFixture(&shape, 2.0f);/// CreateFixture fixes the shape of body as defined  
        }
        b2RevoluteJointDef jd;//a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
        b2Vec2 anchor;/// a point. (type - b2Vec2) 
        anchor.Set(-22.5f, 30.0f);///function which sets coordinates of anchor
        jd.Initialize(b2, b4, anchor);///jd is then initialized as a revolute joint 
        m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
    }
    {
        b2Body* b2;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.25f, 0.25f);///< SetAsBox sets the dimensions of box(shape) 

          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.position.Set(-20.5f, 30.0f);/// Sets the position of body to be created
          b2 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          b2->CreateFixture(&shape, 10.0f);/// CreateFixture fixes the shape of body as defined  
        }
        b2Body* b4;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.5f, 0.5f);///< SetAsBox sets the dimensions of box(shape) 

          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.type = b2_dynamicBody;/// Sets the type of body to be created
          bd.position.Set(-20.5f, 21.0f);/// Sets the position of body to be created
          b4 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          b4->CreateFixture(&shape, 2.0f);/// CreateFixture fixes the shape of body as defined  
        }
        b2RevoluteJointDef jd;//a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
        b2Vec2 anchor;/// a point. (type - b2Vec2) 
        anchor.Set(-20.5f, 30.0f);///function which sets coordinates of anchor
        jd.Initialize(b2, b4, anchor);///jd is then initialized as a revolute joint 
        m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
    }
   {
        b2Body* b2;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.25f, 0.25f);///< SetAsBox sets the dimensions of box(shape) 

          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.position.Set(-18.5f, 30.0f);/// Sets the position of body to be created
          b2 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          b2->CreateFixture(&shape, 10.0f);/// CreateFixture fixes the shape of body as defined  
        }
        b2Body* b4;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.5f, 0.5f);   ///< SetAsBox sets the dimensions of box(shape) 

          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.type = b2_dynamicBody;/// Sets the type of body to be created
          bd.position.Set(-18.5f, 21.0f);/// Sets the position of body to be created
          b4 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          b4->CreateFixture(&shape, 2.0f);/// CreateFixture fixes the shape of body as defined  
        }
        b2RevoluteJointDef jd;//a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
        b2Vec2 anchor;/// a point. (type - b2Vec2) 
        anchor.Set(-18.5f, 30.0f);///function which sets coordinates of anchor
        jd.Initialize(b2, b4, anchor);///jd is then initialized as a revolute joint 
        m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
    }
   {
        b2Body* b2;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.25f, 0.25f);///< SetAsBox sets the dimensions of box(shape) 

          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.position.Set(-16.5f, 30.0f);/// Sets the position of body to be created
          b2 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          b2->CreateFixture(&shape, 10.0f);/// CreateFixture fixes the shape of body as defined  
        }
        b2Body* b4;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.5f, 0.5f);///< SetAsBox sets the dimensions of box(shape) 

          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.type = b2_dynamicBody;/// Sets the type of body to be created
          bd.position.Set(-16.5f, 21.0f);/// Sets the position of body to be created
          b4 = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          b4->CreateFixture(&shape, 2.0f);/// CreateFixture fixes the shape of body as defined  
        }
        b2RevoluteJointDef jd;//a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
        b2Vec2 anchor;/// a point. (type - b2Vec2) 
        anchor.Set(-16.5f, 30.0f);///function which sets coordinates of anchor
        jd.Initialize(b2, b4, anchor);///jd is then initialized as a revolute joint 
        m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
    }
  }
      //sphere near dominos
     /** \brief THIS BLOCK CREATES SPHERE TO BE PLACED NEXT TO THE DOMINOS */
  {
      b2Body* spherebody;
  
      b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
      circle.m_radius = 0.5;///>sets the radius
  
      b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
      ballfd.shape = &circle;///fixes the shape of ballfd
      ballfd.density = 100.0f;///fixes the density of ballfd
      ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
      ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
      //for (int i = 0; i < 10; ++i)
      b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
      ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
      ballbd.position.Set(-37.5f, 20.5f);///sets the position of ballfd
      spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
      spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined  
  }
  //horizontal shelf,seesaw,box,sphere
       /** \brief THIS BLOCK CREATES HORIZONTAL SHELF,SEESAW,BOX,SPHERE SYSTEMT LEFT OF MIDDLE PULLEY */
    {
     // horizontal shelf
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(7.0f, 0.1f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(10.5f, 28.0f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined  
      //triangular wedge
      b2Body* sbody;
      b2PolygonShape poly;///< creates a variable poly of type b2PolygonShape
      b2Vec2 vertices[3];///Creates an array of type b2Vec2 
      vertices[0].Set(-1,0);///sets each of the vertices of wedge
      vertices[1].Set(1,0);///sets each of the vertices of wedge
      vertices[2].Set(0,1.5);///sets each of the vertices of wedge
      poly.Set(vertices, 3);///function which sets the polygon to a polygon shape with \b 3 vertices,
      b2FixtureDef wedgefd;///a fixture defintion (type - b2FixtureDef)
      wedgefd.shape = &poly;///fixes the shape of wedgefd
      wedgefd.density = 10.0f;///fixes the density of wedgefd
      wedgefd.friction = 0.0f;///fixes the friction coefficient of wedgefd
      wedgefd.restitution = 0.0f;///fixes the coefficient of restitution of wedgefd
      b2BodyDef wedgebd;///a body defintion (type - b2BodyDef).
      wedgebd.position.Set(10.5f, 28.0f);///sets the position of wedge
      sbody = m_world->CreateBody(&wedgebd);///creates the wedge
      sbody->CreateFixture(&wedgefd);///fixes the shape of wedge as defined
      
      //The plank on top of the wedge
      shape.SetAsBox(5.08f, 0.1f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd2;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd2.position.Set(10.5f, 29.5f);/// Sets the position of body to be created
      bd2.type = b2_dynamicBody;/// Sets the type of body to be created
      b2Body* body = m_world->CreateBody(&bd2);/// CreateBody creates the body in simulation
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.f;///fixes the density of plank on wedge
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;///sets the shape of plank on wedge
      body->CreateFixture(fd2);/// CreateFixture fixes the shape of body as defined  

      b2RevoluteJointDef jd;//a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
      b2Vec2 anchor;/// a point. (type - b2Vec2) 
      anchor.Set(10.5f,29.0f);///function which sets coordinates of anchor
      jd.Initialize(sbody, body, anchor);///jd is then initialized as a revolute joint 
      m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
      //box beside the see saw
      b2PolygonShape shape2;///< shape2 is variable of type b2PolygonShape
      shape2.SetAsBox(1.0f,0.5f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd3;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd3.position.Set(4.5f, 28.5f);/// Sets the position of body to be created
      //bd3.type = b2_dynamicBody;
      b2Body* body3 = m_world->CreateBody(&bd3);/// CreateBody creates the body in simulation
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 0.1f;///fixes the density of plank on wedge
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;///sets the shape of plank on wedge
      body3->CreateFixture(fd3);/// CreateFixture fixes the shape of body as defined  
     //sphere on the box
      b2Body* spherebody;
  
      b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
      circle.m_radius = 1.0;///>sets the radius
  
      b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
      ballfd.shape = &circle;///fixes the shape of ballfd
      ballfd.density = 3.0f;///fixes the density of ballfd
      ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
      ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
      //for (int i = 0; i < 10; ++i)
      b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
      ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
      ballbd.position.Set(4.5f, 30.5f);///sets the position of ballfd
      spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
      spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined  
    }
    //rightpart
  //horizontal shelf,seesaw,box,sphere SYSTEMS
      /** \brief THIS BLOCK CREATES HORIZONTAL SHELF,SEESAW,BOX,SPHERE SYSTEMS TO RIGHT OF MIDDLE PULLEY */
   {
    {
     // horizontal shelf
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(7.0f, 0.1f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(29.5f, 28.0f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined  
      //triangular wedge
      b2Body* sbody;
      b2PolygonShape poly;///< creates a variable poly of type b2PolygonShape
      b2Vec2 vertices[3];///Creates an array of type b2Vec2 
      vertices[0].Set(-1,0);///sets each of the vertices of wedge
      vertices[1].Set(1,0);///sets each of the vertices of wedge
      vertices[2].Set(0,1.5);///sets each of the vertices of wedge
      poly.Set(vertices, 3);///function which sets the polygon to a polygon shape with \b 3 vertices,
      b2FixtureDef wedgefd;///a fixture defintion (type - b2FixtureDef)
      wedgefd.shape = &poly;///fixes the shape of wedgefd
      wedgefd.density = 10.0f;///fixes the density of wedgefd
      wedgefd.friction = 0.0f;///fixes the friction coefficient of wedgefd
      wedgefd.restitution = 0.0f;///fixes the coefficient of restitution of wedgefd
      b2BodyDef wedgebd;///a body defintion (type - b2BodyDef).
      wedgebd.position.Set(29.5f, 28.0f);///sets the position of wedge
      sbody = m_world->CreateBody(&wedgebd);///creates the wedge
      sbody->CreateFixture(&wedgefd);///fixes the shape of wedge as defined
      
      //The plank on top of the wedge
      shape.SetAsBox(5.18f, 0.1f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd2;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd2.position.Set(29.5f, 29.5f);/// Sets the position of body to be created
      bd2.type = b2_dynamicBody;/// Sets the type of body to be created
      b2Body* body = m_world->CreateBody(&bd2);/// CreateBody creates the body in simulation
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.f;///fixes the density of plank on wedge
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;///sets the shape of plank on wedge
      body->CreateFixture(fd2);/// CreateFixture fixes the shape of body as defined  

      b2RevoluteJointDef jd;//a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
      b2Vec2 anchor;/// a point. (type - b2Vec2) 
      anchor.Set(29.5f,29.0f);///function which sets coordinates of anchor
      jd.Initialize(sbody, body, anchor);///jd is then initialized as a revolute joint 
      m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
      //box beside the see saw
      b2PolygonShape shape2;///< shape2 is variable of type b2PolygonShape
      shape2.SetAsBox(1.0f,0.5f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd3;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd3.position.Set(35.6f, 28.5f);/// Sets the position of body to be created
      //bd3.type = b2_dynamicBody;
      b2Body* body3 = m_world->CreateBody(&bd3);/// CreateBody creates the body in simulation
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 0.1f;///fixes the density of plank on wedge
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;///sets the shape of plank on wedge
      body3->CreateFixture(fd3);/// CreateFixture fixes the shape of body as defined  
     //sphere on the box
      b2Body* spherebody;
  
      b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
      circle.m_radius = 1.0;///>sets the radius
  
      b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
      ballfd.shape = &circle;///fixes the shape of ballfd
      ballfd.density = 3.0f;///fixes the density of ballfd
      ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
      ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
      //for (int i = 0; i < 10; ++i)
      b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
      ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
      ballbd.position.Set(35.6f, 30.5);///sets the position of ballfd
      spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
      spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
      {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(0.2f,0.8f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(22.5f, 28.4f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined  
      } 
    }
    {
     // horizontal shelf
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(7.0f, 0.1f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(43.0f, 23.0f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined  
      //triangular wedge
      b2Body* sbody;
      b2PolygonShape poly;///< creates a variable poly of type b2PolygonShape
      b2Vec2 vertices[3];///Creates an array of type b2Vec2 
      vertices[0].Set(-1,0);///sets each of the vertices of wedge
      vertices[1].Set(1,0);///sets each of the vertices of wedge
      vertices[2].Set(0,1.5);///sets each of the vertices of wedge
      poly.Set(vertices, 3);///function which sets the polygon to a polygon shape with \b 3 vertices,
      b2FixtureDef wedgefd;///a fixture defintion (type - b2FixtureDef)
      wedgefd.shape = &poly;///fixes the shape of wedgefd
      wedgefd.density = 10.0f;///fixes the density of wedgefd
      wedgefd.friction = 0.0f;///fixes the friction coefficient of wedgefd
      wedgefd.restitution = 0.0f;///fixes the coefficient of restitution of wedgefd
      b2BodyDef wedgebd;///a body defintion (type - b2BodyDef).
      wedgebd.position.Set(43.0f, 23.0f);///sets the position of wedge
      sbody = m_world->CreateBody(&wedgebd);///creates the wedge
      sbody->CreateFixture(&wedgefd);///fixes the shape of wedge as defined
      
      //The plank on top of the wedge
      shape.SetAsBox(5.18f, 0.1f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd2;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd2.position.Set(43.f, 24.5f);/// Sets the position of body to be created
      bd2.type = b2_dynamicBody;/// Sets the type of body to be created
      b2Body* body = m_world->CreateBody(&bd2);/// CreateBody creates the body in simulation
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.f;///fixes the density of plank on wedge
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;///sets the shape of plank on wedge
      body->CreateFixture(fd2);/// CreateFixture fixes the shape of body as defined  

      b2RevoluteJointDef jd;//a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
      b2Vec2 anchor;/// a point. (type - b2Vec2) 
      anchor.Set(43.0f,24.0f);///function which sets coordinates of anchor
      jd.Initialize(sbody, body, anchor);///jd is then initialized as a revolute joint 
      m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
      //box beside the see saw
      b2PolygonShape shape2;///< shape2 is variable of type b2PolygonShape
      shape2.SetAsBox(1.0f,0.5f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd3;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd3.position.Set(49.1f, 23.5f);/// Sets the position of body to be created
      //bd3.type = b2_dynamicBody;
      b2Body* body3 = m_world->CreateBody(&bd3);/// CreateBody creates the body in simulation
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 0.1f;///fixes the density of plank on wedge
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;///sets the shape of plank on wedge
      body3->CreateFixture(fd3);/// CreateFixture fixes the shape of body as defined  
     //sphere on the box
      b2Body* spherebody;
  
      b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
      circle.m_radius = 1.0;///>sets the radius
  
      b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
      ballfd.shape = &circle;///fixes the shape of ballfd
      ballfd.density = 3.0f;///fixes the density of ballfd
      ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
      ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
      //for (int i = 0; i < 10; ++i)
      b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
      ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
      ballbd.position.Set(49.1f, 25.5);///sets the position of ballfd
      spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
      spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
      {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(0.2f,0.8f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(36.0f, 23.4f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined  
      } 
    }
    {
     // horizontal shelf
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(7.0f, 0.1f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(56.5f, 18.0f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined  
      //triangular wedge
      b2Body* sbody;
      b2PolygonShape poly;///< creates a variable poly of type b2PolygonShape
      b2Vec2 vertices[3];///Creates an array of type b2Vec2 
      vertices[0].Set(-1,0);///sets each of the vertices of wedge
      vertices[1].Set(1,0);///sets each of the vertices of wedge
      vertices[2].Set(0,1.5);///sets each of the vertices of wedge
      poly.Set(vertices, 3);///function which sets the polygon to a polygon shape with \b 3 vertices,
      b2FixtureDef wedgefd;///a fixture defintion (type - b2FixtureDef)
      wedgefd.shape = &poly;///fixes the shape of wedgefd
      wedgefd.density = 10.0f;///fixes the density of wedgefd
      wedgefd.friction = 0.0f;///fixes the friction coefficient of wedgefd
      wedgefd.restitution = 0.0f;///fixes the coefficient of restitution of wedgefd
      b2BodyDef wedgebd;///a body defintion (type - b2BodyDef).
      wedgebd.position.Set(56.5f, 18.0f);///sets the position of wedge
      sbody = m_world->CreateBody(&wedgebd);///creates the wedge
      sbody->CreateFixture(&wedgefd);///fixes the shape of wedge as defined
      
      //The plank on top of the wedge
      shape.SetAsBox(5.18f, 0.1f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd2;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd2.position.Set(56.5f, 19.5f);/// Sets the position of body to be created
      bd2.type = b2_dynamicBody;/// Sets the type of body to be created
      b2Body* body = m_world->CreateBody(&bd2);/// CreateBody creates the body in simulation
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.f;///fixes the density of plank on wedge
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;///sets the shape of plank on wedge
      body->CreateFixture(fd2);/// CreateFixture fixes the shape of body as defined  

      b2RevoluteJointDef jd;//a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
      b2Vec2 anchor;/// a point. (type - b2Vec2) 
      anchor.Set(56.5f,19.0f);///function which sets coordinates of anchor
      jd.Initialize(sbody, body, anchor);///jd is then initialized as a revolute joint 
      m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
      //box beside the see saw
      b2PolygonShape shape2;///< shape2 is variable of type b2PolygonShape
      shape2.SetAsBox(1.0f,0.5f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd3;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd3.position.Set(62.6f, 18.5f);/// Sets the position of body to be created
      //bd3.type = b2_dynamicBody;
      b2Body* body3 = m_world->CreateBody(&bd3);/// CreateBody creates the body in simulation
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 0.1f;///fixes the density of plank on wedge
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;///sets the shape of plank on wedge
      body3->CreateFixture(fd3);/// CreateFixture fixes the shape of body as defined  
     //sphere on the box
      b2Body* spherebody;
  
      b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
      circle.m_radius = 1.0;///>sets the radius
  
      b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
      ballfd.shape = &circle;///fixes the shape of ballfd
      ballfd.density = 3.0f;///fixes the density of ballfd
      ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
      ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
      //for (int i = 0; i < 10; ++i)
      b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
      ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
      ballbd.position.Set(62.6f, 20.5);///sets the position of ballfd
      spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
      spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
      {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(0.2f,0.8f);///< SetAsBox sets the dimensions of box(shape) 

      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(49.9f, 18.4f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined  
      } 
    }
 }
  //The middle pulley system
        /** \brief THIS BLOCK CREATES THE ENTIRE MIDDLE PULLEY SYSTEM  ALONG WITH ITS COMPONENTS*/
    {
      
    {
      b2Body* sbody;
      b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
      circle.m_radius = 0.75f;///>sets the radius
      b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
      ballfd.shape = &circle;///fixes the shape of ballfd
      ballfd.density = 50.0f;///fixes the density of ballfd
      ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
      ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
      b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
      ballbd.type = b2_staticBody;///type set to b2_dynamicBody
      ballbd.position.Set(15.0f, 40);///sets the position of ballfd
      sbody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
      sbody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
        }
      {
          b2Body* sbody;
          b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
          circle.m_radius = 0.75f;///>sets the radius
          b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
          ballfd.shape = &circle;///fixes the shape of ballfd
          ballfd.density = 50.0f;///fixes the density of ballfd
          ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
          ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
          b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
          ballbd.type = b2_staticBody;///type set to b2_dynamicBody
          ballbd.position.Set(25.0f, 40.0);///sets the position of ballfd
          sbody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
          sbody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
        }
      {
      //the two boxes of middle pulley
      b2PolygonShape shape;///<shape of variable b2PolygonShape is defined 
      shape.SetAsBox(1.0f, 1.0f);///< SetAsBox sets the dimensions of box(shape) 
      b2BodyDef bd1;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      b2BodyDef bd2;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd1.position.Set(15.0f, 35.0f);/// Sets the position of object to be created
      bd1.type = b2_dynamicBody;///type set to b2_dynamicBody
      bd2.position.Set(25.0f, 35.0f);/// Sets the position of object to be created
      bd2.type = b2_dynamicBody;///type set to b2_dynamicBody
      b2Body* body1 = m_world->CreateBody(&bd1);/// CreateBody creates the body in simulation
      b2Body* body2 = m_world->CreateBody(&bd2);/// CreateBody creates the body in simulation
      b2FixtureDef *fd = new b2FixtureDef;
      fd->density = 10.f;///fixes the density of the fd
      fd->shape = new b2PolygonShape;
      fd->shape = &shape;///fixes the shape of the fd
      body1->CreateFixture(fd);/// CreateFixture fixes the shape of body as defined
      body2->CreateFixture(fd);/// CreateFixture fixes the shape of body as defined
      //the middle joint for pulley
      b2Body* sbody;
      b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
      circle.m_radius = 0.05;///>sets the radius
      b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
      ballfd.shape = &circle;///fixes the shape of ballfd
      ballfd.density = 30.0f;///fixes the density of ballfd
      ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
      ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
      b2BodyDef ballbd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
      ballbd.position.Set(20.f, 30.f);/// Sets the position of object to be created
      sbody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
      sbody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined
      // The pulley joint left half
      b2PulleyJointDef* myjoint1 = new b2PulleyJointDef();
      b2Vec2 worldAnchorOnBody11(15, 35.5); // Anchor point on body 1 in world axis
      b2Vec2 worldAnchorOnBody12(20, 30); // Anchor point on body 2 in world axis
      b2Vec2 worldAnchorGround11(15, 40); // Anchor point for ground 1 in world axis
      b2Vec2 worldAnchorGround12(15, 40); // Anchor point for ground 2 in world axis
      float32 ratio1 = 1.0f; // Define ratio
      myjoint1->Initialize(body1, sbody, worldAnchorGround11, worldAnchorGround12, body1->GetWorldCenter(), sbody->GetWorldCenter(), ratio1);///initializes the joint
      m_world->CreateJoint(myjoint1);/// CreateJoint creates the joint in simulation
    
      // The pulley joint right half
      b2PulleyJointDef* myjoint2 = new b2PulleyJointDef();
      b2Vec2 worldAnchorOnBody21(25, 35.5); // Anchor point on body 1 in world axis
      b2Vec2 worldAnchorOnBody22(20, 30); // Anchor point on body 2 in world axis
      b2Vec2 worldAnchorGround21(25, 40); // Anchor point for ground 1 in world axis
      b2Vec2 worldAnchorGround22(25, 40); // Anchor point for ground 2 in world axis
      float32 ratio2 = 1.0f; // Define ratio
      myjoint2->Initialize(body2, sbody, worldAnchorGround21, worldAnchorGround22, body2->GetWorldCenter(), sbody->GetWorldCenter(), ratio2);///initializes the joint
      m_world->CreateJoint(myjoint2);/// CreateJoint creates the joint in simulation
      //bottom joint for pan
      b2Body* sbody2;
      b2CircleShape circle2;///>Creates a circle shape (type - b2CircleShape)
      circle2.m_radius = 0.05;///>sets the radius
      b2FixtureDef ballfd2;///ballfd2 is a variable of type b2FixtureDef
      ballfd2.shape = &circle2;///fixes the shape of ballfd2
      ballfd2.density = 30.0f;///fixes the density of ballfd2
      ballfd2.friction = 0.0f;///fixes the coefficient of friction of ballfd2
      ballfd2.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
      b2BodyDef ballbd2;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      ballbd2.type = b2_dynamicBody;///type set to b2_dynamicBody
      ballbd2.position.Set(20.f, 10.f);/// Sets the position of object to be created
      sbody2 = m_world->CreateBody(&ballbd2);/// CreateBody creates the body in simulation
      sbody2->CreateFixture(&ballfd2);/// CreateFixture fixes the shape of body as defined
      //thread connecting two joints
      b2DistanceJointDef jointDef;
      b2Vec2 worldAnchorOnBodyA(20, 30); // Anchor point on body A in world axis
      b2Vec2 worldAnchorOnBodyB(20, 10); // Anchor point on body B in world axis
      jointDef.Initialize(sbody, sbody2, worldAnchorOnBodyA, worldAnchorOnBodyB);///initializes the joint
      jointDef.collideConnected = false;/// bodies collide independently (collideConnected = false)
      jointDef.frequencyHz = 0.0f;
      jointDef.dampingRatio = 1.f;
      m_world->CreateJoint(&jointDef);/// CreateJoint creates the joint in simulation
      //open box at bottom of pulley
      b2BodyDef *bd = new b2BodyDef;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd->type = b2_dynamicBody;///type set to b2_dynamicBody
      bd->position.Set(20,-3);/// Sets the position of object to be created
      bd->fixedRotation = true;
      b2FixtureDef *fd1 = new b2FixtureDef;
      fd1->density = 10.0;///fixes the density of the fd1
      fd1->friction = 0.5;///fixes the friction of the fd1
      fd1->restitution = 0.f;///fixes the restitution of fd1
      fd1->shape = new b2PolygonShape;
      b2PolygonShape bs1;
      bs1.SetAsBox(4,0.2, b2Vec2(0.f,-1.9f), 0);///< SetAsBox sets the dimensions of box(shape) 
      fd1->shape = &bs1;///fixes the shape of the fd1
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.0;///fixes the density of the fd2
      fd2->friction = 0.5;///fixes the friction of the fd2
      fd2->restitution = 0.f;///fixes the restitution of fd2
      fd2->shape = new b2PolygonShape;
      b2PolygonShape bs2;
      bs2.SetAsBox(0.2,1, b2Vec2(4.0f,-1.f), 0);///< SetAsBox sets the dimensions of box(shape) 
      fd2->shape = &bs2;///fixes the shape of the fd2
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 10.0;///fixes the density of the fd3
      fd3->friction = 0.5;///fixes the friction of the fd3
      fd3->restitution = 0.f;///fixes the restitution of fd3
      fd3->shape = new b2PolygonShape;
      b2PolygonShape bs3;
      bs3.SetAsBox(0.2,1, b2Vec2(-4.0f,-1.f), 0);///< SetAsBox sets the dimensions of box(shape) 
      fd3->shape = &bs3;
      b2Body* box1 = m_world->CreateBody(bd);/// CreateBody creates the body in simulation
      box1->CreateFixture(fd1);/// CreateFixture fixes the shape of body as defined
      box1->CreateFixture(fd2);/// CreateFixture fixes the shape of body as defined
      box1->CreateFixture(fd3);/// CreateFixture fixes the shape of body as defined
      //threads connecting 2nd joint and openbox
      b2DistanceJointDef jointDef1;
      b2DistanceJointDef jointDef2;
      b2Vec2 worldAnchorOnBodyA1(20, 10); // Anchor point on body A in world axis
      b2Vec2 worldAnchorOnBodyB1(16, -3); // Anchor point on body B in world axis
      b2Vec2 worldAnchorOnBodyA2(20, 10); // Anchor point on body A in world axis
      b2Vec2 worldAnchorOnBodyB2(24, -3); // Anchor point on body B in world axis
      jointDef1.Initialize(sbody2, box1, worldAnchorOnBodyA1, worldAnchorOnBodyB1);///initializes the joint
      jointDef2.Initialize(sbody2, box1, worldAnchorOnBodyA2, worldAnchorOnBodyB2);///initializes the joint
      jointDef1.collideConnected = false; ///bodies collide independently (collideConnected = false)
      jointDef1.frequencyHz = 0.0f;
      jointDef1.dampingRatio = 1.f;
      m_world->CreateJoint(&jointDef1);/// CreateJoint creates the joint in simulation
      jointDef2.collideConnected = false;/// bodies collide independently (collideConnected = false)
      jointDef2.frequencyHz = 0.0f;
      jointDef2.dampingRatio = 1.f;
      m_world->CreateJoint(&jointDef2);/// CreateJoint creates the joint in simulation
      }
    }
   //horizontal shelf,seesaw with dominos on it
           /** \brief THIS BLOCK CREATES HORIZONTAL SHELF,SEESAW WITH DOMINOS ON BOTH SIDES OF IT */
    {
     // horizontal shelf
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(11.0f, 0.2f);///< SetAsBox sets the dimensions of box(shape) 
  
      b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(70.5f, 9.9f);/// Sets the position of object to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined
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
      shape.SetAsBox(6.0f, 0.1f);///< SetAsBox sets the dimensions of box(shape) 
      b2BodyDef bd2;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd2.position.Set(70.5f, 11.5f);/// Sets the position of object to be created
      bd2.type = b2_dynamicBody;///type set to b2_dynamicBody
      b2Body* body = m_world->CreateBody(&bd2);/// CreateBody creates the body in simulation
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.f;///fixes the density of the fd2
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;///fixes the shape of the fd2
      body->CreateFixture(fd2);/// CreateFixture fixes the shape of body as defined

      b2RevoluteJointDef jd;
      b2Vec2 anchor;
      anchor.Set(70.5f,11.0f);
      jd.Initialize(sbody, body, anchor);
      m_world->CreateJoint(&jd);
     {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(0.1f, 6.6f);///< SetAsBox sets the dimensions of box(shape) 
  
      b2FixtureDef fd;
      fd.shape = &shape;///fixes the shape of the fd
      fd.density = 0.01f;///fixes the density of the fd
      fd.friction = 0.1f;///fixes the friction of the fd
    
     // for (int i = 0; i < 11; ++i)
       {
         b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
         bd.type = b2_dynamicBody;/// Sets the  typeof object to be created
         bd.position.Set(76.0f,19.0f);/// Sets the position of object to be created
        b2Body* body = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
        body->CreateFixture(&fd);/// CreateFixture fixes the shape of body as defined
       } 
       {
         b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
         bd.type = b2_dynamicBody;///type set to b2_dynamicBody
         bd.position.Set(65.0f,19.0f);/// Sets the position of object to be created
        b2Body* body = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
        body->CreateFixture(&fd);/// CreateFixture fixes the shape of body as defined
       } 
      } 
       {
        b2PolygonShape shape;///< shape is variable of type b2PolygonShape
        shape.SetAsBox(0.2f, 0.8f);///< SetAsBox sets the dimensions of box(shape) 
  
        b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
        bd.position.Set(59.5f, 10.3f);/// Sets the position of object to be created
        b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
        ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined
      } 
      {
        b2PolygonShape shape;///< shape is variable of type b2PolygonShape
        shape.SetAsBox(0.2f, 0.8f);///< SetAsBox sets the dimensions of box(shape) 
  
        b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
        bd.position.Set(81.5f, 10.3f);/// Sets the position of object to be created
        b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
        ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined
      }         
    }

//The right pulley system
            /** \brief THIS BLOCK CREATES THE ENTIRE RIGHT  PULLEY SYSTEM  ALONG WITH ITS COMPONENTS*/
  { 
      b2BodyDef *bd = new b2BodyDef;
      bd->type = b2_dynamicBody;
      bd->position.Set(112,2);
      bd->fixedRotation = true;

      //The open box
      b2FixtureDef *fd1 = new b2FixtureDef;
      fd1->density = 10.0;///fixes the density of the fd1
      fd1->friction = 0.5;///fixes the friction coefficient of the fd1
      fd1->restitution = 0.f;///fixes the friction coefficient of the fd1
      fd1->shape = new b2PolygonShape;
      b2PolygonShape bs1;
      bs1.SetAsBox(1.5,0.2, b2Vec2(0.f,-1.4f), 0);
      fd1->shape = &bs1;///fixes the shape of the fd1
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.0;///fixes the density of the fd2
      fd2->friction = 0.5;///fixes the friction coefficient of the fd2
      fd2->restitution = 0.f;///fixes the friction coefficient of the fd2
      fd2->shape = new b2PolygonShape;
      b2PolygonShape bs2;
      bs2.SetAsBox(0.2,1.5, b2Vec2(1.5f,0.f), 0);
      fd2->shape = &bs2;///fixes the shape of the fd2
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 10.0;///fixes the density of the fd3
      fd3->friction = 0.5;///fixes the friction coefficient of the fd3
      fd3->restitution = 0.f;///fixes the friction coefficient of the fd3
      fd3->shape = new b2PolygonShape;
      b2PolygonShape bs3;
      bs3.SetAsBox(0.2,1.5, b2Vec2(-1.5f,0.f), 0);
      fd3->shape = &bs3;///fixes the shape of the fd3
      b2FixtureDef *fd4 = new b2FixtureDef;
      fd4->density = 10.0;///fixes the density of the fd3
      fd4->friction = 0.5;///fixes the friction coefficient of the fd3
      fd4->restitution = 0.f;///fixes the friction coefficient of the fd3
      fd4->shape = new b2PolygonShape;
      b2PolygonShape bs4;
      bs4.SetAsBox(1.5, 0.2, b2Vec2(0.f,1.4f), 0);
      fd4->shape = &bs4;


      b2Body* box1 = m_world->CreateBody(bd); 
      box1->CreateFixture(fd1);/// CreateFixture fixes the shape of fd1 as defined
      box1->CreateFixture(fd2);/// CreateFixture fixes the shape of fd2 as defined
      box1->CreateFixture(fd3);/// CreateFixture fixes the shape of fd3 as defined
      box1->CreateFixture(fd4);/// CreateFixture fixes the shape of fd4 as defined
      //The bar
      bd->position.Set(92,20);/// Sets the position of bar to be created
      fd1->density = 40.15;///fixes the density of the bar
      b2Body* box2 = m_world->CreateBody(bd);
      box2->CreateFixture(fd1);/// CreateFixture fixes the shape of bar as defined

      // The pulley joint
      b2PulleyJointDef* myjoint = new b2PulleyJointDef();
      b2Vec2 worldAnchorOnBody1(112, 2); // Anchor point on body 1 in world axis
      b2Vec2 worldAnchorOnBody2(92,20); // Anchor point on body 2 in world axis
      b2Vec2 worldAnchorGround1(112, 37); // Anchor point for ground 1 in world axis
      b2Vec2 worldAnchorGround2(92, 37); // Anchor point for ground 2 in world axis
      float32 ratio = 1.0f; // Define ratio
      myjoint->Initialize(box1, box2, worldAnchorGround1, worldAnchorGround2, box1->GetWorldCenter(), box2->GetWorldCenter(), ratio);
      m_world->CreateJoint(myjoint);
    }
     //rod fixed with ball on it   
   {
        b2Body* b2;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(2.25f, 0.2f);///< SetAsBox sets the dimensions of box(shape) 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.position.Set(83.f, 30.0f);/// Sets the position of dominos to be created
          b2 = m_world->CreateBody(&bd);///creates the body in simulation
          b2->CreateFixture(&shape, 10.0f);/// CreateFixture fixes the shape as defined
        }
        b2Body* b4;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(7.5f, 0.2f);///< SetAsBox sets the dimensions of box(shape) 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.type = b2_dynamicBody;///sets the type of the body yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
          bd.position.Set(83.f, 26.0f);/// Sets the position of dominos to be created
          b4 = m_world->CreateBody(&bd);///creates the body in simulation
          b4->CreateFixture(&shape, 2.0f);/// CreateFixture fixes the shape as defined
        }
        b2RevoluteJointDef jd;///a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
        b2Vec2 anchor;/// a point. (type - b2Vec2) 
        anchor.Set(83.f, 30.0f);///function which sets coordinates of anchor
        jd.Initialize(b2, b4, anchor);///jd is then initialized as a revolute joint 
        m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
        {
          b2Body* spherebody;
          b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
          circle.m_radius = 1.0f;///>sets the radius
          b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
          ballfd.shape = &circle;///fixes the shape of ballfd
          ballfd.density = 3.0f;///fixes the density of ballfd
          ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
          ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
          b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
          ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
          ballbd.position.Set(89.0f, 27.5);///sets the position of ballfd
          spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
          spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
        }
        {
          b2Body* spherebody;
          b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
          circle.m_radius = 1.0f;///>sets the radius
          b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
          ballfd.shape = &circle;///fixes the shape of ballfd
          ballfd.density = 3.0f;///fixes the density of ballfd
          ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
          ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
          b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
          ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
          ballbd.position.Set(77.0,27.5);///sets the position of ballfd
          spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
          spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
        }
   }
        //The revolving horizontal platform
              /** \brief THIS BLOCK CREATES HORIZONTAL PLATFORM WITH BALLS ON IT*/ 
   {
        b2Body* b2;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.01f, 0.01f);///< SetAsBox sets the dimensions of box(shape) 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.position.Set(108.f, 12.01f);/// Sets the position of dominos to be created
          b2 = m_world->CreateBody(&bd);///creates the body in simulation
          b2->CreateFixture(&shape, 10.0f);/// CreateFixture fixes the shape as defined
        }
        b2Body* b4;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(3.0f, 0.1f);///< SetAsBox sets the dimensions of box(shape) 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.type = b2_dynamicBody;///sets the type of the body yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
          bd.position.Set(108.f, 12.0f);/// Sets the position of dominos to be created
          b4 = m_world->CreateBody(&bd);///creates the body in simulation
          b4->CreateFixture(&shape, 2.0f);/// CreateFixture fixes the shape as defined
        }
        b2RevoluteJointDef jd;///a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
        b2Vec2 anchor;/// a point. (type - b2Vec2) 
        anchor.Set(108.f, 12.0f);///function which sets coordinates of anchor
        jd.Initialize(b2, b4, anchor);///jd is then initialized as a revolute joint 
        m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
        {
          b2Body* spherebody;
          b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
          circle.m_radius = 0.5f;///>sets the radius
          b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
          ballfd.shape = &circle;///fixes the shape of ballfd
          ballfd.density = 20.0f;///fixes the density of ballfd
          ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
          ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
          b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
          ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
          ballbd.position.Set(106.0f, 12.5);///sets the position of ballfd
          spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
          spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
        }
        {
          b2Body* spherebody;
          b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
          circle.m_radius = 0.5f;///>sets the radius
          b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
          ballfd.shape = &circle;///fixes the shape of ballfd
          ballfd.density = 20.0f;///fixes the density of ballfd
          ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
          ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
          b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
          ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
          ballbd.position.Set(110.0f, 12.5);///sets the position of ballfd
          spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
          spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
        }
   }
    // horizontal,vertical shelf
                  /** \brief THIS BLOCK CREATES HORIZONTAL,VERTICAL SHELFES TO HOLD FALLING BALL,PLATFORM*/
    {
      
      {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(4.0, 0.2f);///< SetAsBox sets the dimensions of box(shape) 

          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.position.Set(92.5f, 7.9f);/// Sets the position of body to be created
          b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined  
     }

      {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.2f, 0.5f);///< SetAsBox sets the dimensions of box(shape) 

          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.position.Set(88.5f, 8.1f);/// Sets the position of body to be created
          b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined  
     }
      {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.2f, 0.5f);///< SetAsBox sets the dimensions of box(shape) 

          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.position.Set(96.5f, 8.1f);/// Sets the position of body to be created
          b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
          ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined  
     }  
    }
 //dominos on ground     
   {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(0.1f, 7.0f);///< SetAsBox sets the dimensions of box(shape) 
  
      b2FixtureDef fd;
      fd.shape = &shape;///fixes the shape of the fd
      fd.density = 20.0f;///fixes the density of the fd
      fd.friction = 0.1f;///fixes the friction of the fd
    
      for (int i = 0; i < 2; ++i)
       {
         b2BodyDef bd;
         bd.type = b2_dynamicBody;///sets the type of bd
         bd.position.Set(0.0f + 8.0f * i, 7.0f);/// Sets the position of dominos to be created
        b2Body* body = m_world->CreateBody(&bd);///creates the dominos
        body->CreateFixture(&fd);/// CreateFixture fixes the shape of fd as defined
       } 
    }
 //revolving platform with balls    
   {
        b2Body* b2;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.01f, 0.01f);///< SetAsBox sets the dimensions of box(shape) 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.position.Set(4.f, 10.01f);/// Sets the position of dominos to be created
          b2 = m_world->CreateBody(&bd);///creates the body in simulation
          b2->CreateFixture(&shape, 10.0f);/// CreateFixture fixes the shape as defined
        }
        b2Body* b4;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(3.2f, 0.1f);///< SetAsBox sets the dimensions of box(shape) 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.type = b2_dynamicBody;///sets the type of the body yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
          bd.position.Set(4.f, 10.0f);/// Sets the position of dominos to be created
          b4 = m_world->CreateBody(&bd);///creates the body in simulation
          b4->CreateFixture(&shape, 2.0f);/// CreateFixture fixes the shape as defined
        }
        b2RevoluteJointDef jd;///a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
        b2Vec2 anchor;/// a point. (type - b2Vec2) 
        anchor.Set(4.f, 10.0f);///function which sets coordinates of anchor
        jd.Initialize(b2, b4, anchor);///jd is then initialized as a revolute joint 
        m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
        {
          b2Body* spherebody;
          b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
          circle.m_radius = 0.5f;///>sets the radius
          b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
          ballfd.shape = &circle;///fixes the shape of ballfd
          ballfd.density = 0.5f;///fixes the density of ballfd
          ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
          ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
          b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
          ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
          ballbd.position.Set(2.0f, 10.5);///sets the position of ballfd
          spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
          spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
        }
        {
          b2Body* spherebody;
          b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
          circle.m_radius = 0.5f;///>sets the radius
          b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
          ballfd.shape = &circle;///fixes the shape of ballfd
          ballfd.density = 0.5f;///fixes the density of ballfd
          ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
          ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
          b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
          ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
          ballbd.position.Set(6.0f, 10.5);///sets the position of ballfd
          spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
          spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
        }
   }
   //revolving platform with balls    
   {
        b2Body* b2;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.01f, 0.01f);///< SetAsBox sets the dimensions of box(shape) 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.position.Set(-4.f, 10.01f);/// Sets the position of dominos to be created
          b2 = m_world->CreateBody(&bd);///creates the body in simulation
          b2->CreateFixture(&shape, 10.0f);/// CreateFixture fixes the shape as defined
        }
        b2Body* b4;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(3.0f, 0.1f);///< SetAsBox sets the dimensions of box(shape) 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.type = b2_dynamicBody;///sets the type of the body yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
          bd.position.Set(-4.f, 10.0f);/// Sets the position of dominos to be created
          b4 = m_world->CreateBody(&bd);///creates the body in simulation
          b4->CreateFixture(&shape, 2.0f);/// CreateFixture fixes the shape as defined
        }
        b2RevoluteJointDef jd;///a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
        b2Vec2 anchor;/// a point. (type - b2Vec2) 
        anchor.Set(-4.f, 10.0f);///function which sets coordinates of anchor
        jd.Initialize(b2, b4, anchor);///jd is then initialized as a revolute joint 
        m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
        {
          b2Body* spherebody;
          b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
          circle.m_radius = 0.5f;///>sets the radius
          b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
          ballfd.shape = &circle;///fixes the shape of ballfd
          ballfd.density = 0.5f;///fixes the density of ballfd
          ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
          ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
          b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
          ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
          ballbd.position.Set(-6.0f, 10.5);///sets the position of ballfd
          spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
          spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
        }
        {
          b2Body* spherebody;
          b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
          circle.m_radius = 0.5f;///>sets the radius
          b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
          ballfd.shape = &circle;///fixes the shape of ballfd
          ballfd.density = 0.5f;///fixes the density of ballfd
          ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
          ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
          b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
          ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
          ballbd.position.Set(-2.0f, 10.5);///sets the position of ballfd
          spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
          spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
        }
   }
   //dominos on ground     
   {
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(0.1f, 7.0f);///< SetAsBox sets the dimensions of box(shape) 
  
      b2FixtureDef fd;
      fd.shape = &shape;///fixes the shape of the fd
      fd.density = 20.0f;///fixes the density of the fd
      fd.friction = 0.0f;///fixes the friction of the fd
    
      for (int i = 0; i < 2; ++i)
       {
         b2BodyDef bd;
         bd.type = b2_dynamicBody;///sets the type of bd
         bd.position.Set(32.0f + 8.0f * i, 7.0f);/// Sets the position of dominos to be created
        b2Body* body = m_world->CreateBody(&bd);///creates the dominos
        body->CreateFixture(&fd);/// CreateFixture fixes the shape of fd as defined
       } 
    } 
 //revolving platform with balls      
   {
        b2Body* b2;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.01f, 0.01f);///< SetAsBox sets the dimensions of box(shape) 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.position.Set(46.f, 8.01f);/// Sets the position of dominos to be created
          b2 = m_world->CreateBody(&bd);///creates the body in simulation
          b2->CreateFixture(&shape, 10.0f);/// CreateFixture fixes the shape as defined
        }
        b2Body* b4;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(3.0f, 0.1f);///< SetAsBox sets the dimensions of box(shape) 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.type = b2_dynamicBody;///sets the type of the body yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
          bd.position.Set(46.f, 8.0f);/// Sets the position of dominos to be created
          b4 = m_world->CreateBody(&bd);///creates the body in simulation
          b4->CreateFixture(&shape, 2.0f);/// CreateFixture fixes the shape as defined
        }
        b2RevoluteJointDef jd;///a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
        b2Vec2 anchor;/// a point. (type - b2Vec2) 
        anchor.Set(46.f, 8.0f);///function which sets coordinates of anchor
        jd.Initialize(b2, b4, anchor);///jd is then initialized as a revolute joint 
        m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
        {
          b2Body* spherebody;
          b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
          circle.m_radius = 0.5f;///>sets the radius
          b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
          ballfd.shape = &circle;///fixes the shape of ballfd
          ballfd.density = 0.7f;///fixes the density of ballfd
          ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
          ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
          b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
          ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
          ballbd.position.Set(44.0f, 8.5);///sets the position of ballfd
          spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
          spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
        }
        {
          b2Body* spherebody;
          b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
          circle.m_radius = 0.5f;///>sets the radius
          b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
          ballfd.shape = &circle;///fixes the shape of ballfd
          ballfd.density = 0.7f;///fixes the density of ballfd
          ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
          ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
          b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
          ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
          ballbd.position.Set(48.0f, 8.5);///sets the position of ballfd
          spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
          spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
        }
   }
  //revolving platform with balls  
   {
        b2Body* b2;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(0.01f, 0.01f);///< SetAsBox sets the dimensions of box(shape) 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.position.Set(36.f, 10.01f);/// Sets the position of dominos to be created
          b2 = m_world->CreateBody(&bd);///creates the body in simulation
          b2->CreateFixture(&shape, 10.0f);/// CreateFixture fixes the shape as defined
        }
        b2Body* b4;
        {
          b2PolygonShape shape;///< shape is variable of type b2PolygonShape
          shape.SetAsBox(3.0f, 0.1f);///< SetAsBox sets the dimensions of box(shape) 
          b2BodyDef bd;///a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
          bd.type = b2_dynamicBody;///sets the type of the body yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
          bd.position.Set(36.f, 10.0f);/// Sets the position of dominos to be created
          b4 = m_world->CreateBody(&bd);///creates the body in simulation
          b4->CreateFixture(&shape, 2.0f);/// CreateFixture fixes the shape as defined
        }
        b2RevoluteJointDef jd;///a revolute joint definition (holds the data needed to construct a revolute joint, type - b2RevoluteJointDef) 
        b2Vec2 anchor;/// a point. (type - b2Vec2) 
        anchor.Set(36.f, 10.0f);///function which sets coordinates of anchor
        jd.Initialize(b2, b4, anchor);///jd is then initialized as a revolute joint 
        m_world->CreateJoint(&jd);/// CreateJoint creates the joint in simulation
        {
          b2Body* spherebody;
          b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
          circle.m_radius = 0.5f;///>sets the radius
          b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
          ballfd.shape = &circle;///fixes the shape of ballfd
          ballfd.density = 0.3f;///fixes the density of ballfd
          ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
          ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
          b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
          ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
          ballbd.position.Set(34.0f, 10.5);///sets the position of ballfd
          spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
          spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
        }
        {
          b2Body* spherebody;
          b2CircleShape circle;///>Creates a circle shape (type - b2CircleShape)
          circle.m_radius = 0.5f;///>sets the radius
          b2FixtureDef ballfd;///ballfd is a variable of type b2FixtureDef
          ballfd.shape = &circle;///fixes the shape of ballfd
          ballfd.density = 0.3f;///fixes the density of ballfd
          ballfd.friction = 0.0f;///fixes the coefficient of friction of ballfd
          ballfd.restitution = 0.0f;///fixes the coefficient of restitution of ballfd
  
          b2BodyDef ballbd;///a body defintion (type - b2BodyDef)
          ballbd.type = b2_dynamicBody;///type set to b2_dynamicBody
          ballbd.position.Set(38.0f, 10.5);///sets the position of ballfd
          spherebody = m_world->CreateBody(&ballbd);/// CreateBody creates the body in simulation
          spherebody->CreateFixture(&ballfd);/// CreateFixture fixes the shape of body as defined 
        }
   }
   //horizontal shelves next to open box in middle pulley
   {
    { 
    
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(2.9f, 0.15f);///< SetAsBox sets the dimensions of box(shape)
  
      b2BodyDef bd;//a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(12.6f, 5.0f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined     
    }
    { 
    
      b2PolygonShape shape;///< shape is variable of type b2PolygonShape
      shape.SetAsBox(2.9f, 0.15f);///< SetAsBox sets the dimensions of box(shape) 
  
      b2BodyDef bd;//a body defintion (holds the data needed to construct a rigid body, type - b2BodyDef) 
      bd.position.Set(27.6f, 5.0f);/// Sets the position of body to be created
      b2Body* ground = m_world->CreateBody(&bd);/// CreateBody creates the body in simulation
      ground->CreateFixture(&shape, 0.0f);/// CreateFixture fixes the shape of body as defined    
   }
  }
 }
  sim_t *sim = new sim_t("Dominos", dominos_t::create);
}
