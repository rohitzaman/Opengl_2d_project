//Basic QUADS
#include <windows.h>
#include <GL/glut.h>

#include <math.h>
#define PI 3.1416

static float	tx	=  0.0;
static float	ty	=  0.0;

static float	tx1	=  1000.0;
static float	ty1	=  0.0;


static float	ox	=  1000.0;
static float	oy	=  0.0;
static float	px	=  1000.0;
static float	py	=  0.0;
static float	ex	=  1000.0;
static float	ey	=  0.0;
static float	nx	=  1000.0;
static float	ny	=  0.0;
static float	gx	=  1000.0;
static float	gy	=  0.0;
static float	lx	=  1000.0;
static float	ly	=  0.0;

static float	sx	=  0.0;
static float	sy	=  0.0;


float spin = 0.0;

float spinC = 0.0;
float spinC1 = 0.0;
float spinC2 = 0.0;



void circle(float radius_x, float radius_y)
{
	int i=0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex2f (cos(angle) * radius_x, sin(angle) * radius_y);
			//glVertex2f (cos(angle) * radius_x+5, sin(angle) * radius_y);
		}

	glEnd();
}
void spinDisplay_left(void)
{
   spin = spin + 6.8; //to increase or decrease speed change the value added to spin
   if (spin > 360.0)
      spin = spin - 360.0;
   //the above if block is given only for clear understanding, otherwise 370 degrees is the same as 10 degrees

   glutPostRedisplay(); //calls the display function again
}




void spinDisplay_right(void)
{
   spin = spin - 5.0;
   if (spin < -360.0)
      spin = spin + 360.0;

   spinC = spinC - 0.2;
   if (spinC < -360.0)
      spinC = spinC + 360.0;
   spinC1 = spinC1 - 0.1;
   if (spinC1 < -360.0)
      spinC1 = spinC1 + 360.0;

   spinC2 = spinC2 - 0.005;
   if (spinC2 < -2.0)
      spinC2 = spinC2 + 2.0;


   glutPostRedisplay();
}
void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case '1':
		    tx +=1000;
            tx1 -=1000;
            PlaySound("board_writing.wav", NULL, SND_FILENAME| SND_ASYNC);
            glutPostRedisplay();
			break;
		case '2':
		    tx -=1000;
            tx1 +=1000;
             PlaySound("opengl.wav", NULL, SND_FILENAME| SND_ASYNC);
            glutPostRedisplay();
			break;


		case 'o':
		    ox -=1000;
		    PlaySound("o.wav", NULL, SND_FILENAME| SND_ASYNC);
            glutPostRedisplay();
			break;
        case 'p':
		    px -=1000;
		    PlaySound("p.wav", NULL, SND_FILENAME| SND_ASYNC);
            glutPostRedisplay();
			break;
        case 'e':
		    ex -=1000;
		    PlaySound("e.wav", NULL, SND_FILENAME| SND_ASYNC);
            glutPostRedisplay();
			break;
		case 'n':
		    nx -=1000;
		    PlaySound("n.wav", NULL, SND_FILENAME| SND_ASYNC);
            glutPostRedisplay();
			break;
		case 'g':
		    gx -=1000;
		    PlaySound("g.wav", NULL, SND_FILENAME| SND_ASYNC);
            glutPostRedisplay();
			break;
		case 'l':
		    lx -=1000;
		    PlaySound("l.wav", NULL, SND_FILENAME| SND_ASYNC);
            glutPostRedisplay();
			break;


		case 'q':
		    sy +=2;

		    PlaySound("what_is_opengl.wav", NULL, SND_FILENAME| SND_ASYNC);
            glutPostRedisplay();
			break;

		case 'a':
		    sy -=2;
		    PlaySound("definition_english.wav", NULL, SND_FILENAME| SND_ASYNC);
            glutPostRedisplay();
			break;

	  default:
			break;
	}
}

void init()
{
    glClearColor(0.0f, 0.5f, 0.5f, 0.0f);
    glOrtho(0,28,0,21,-15,15);
}
void classroom()
{
     //uporer ceiling
    glColor3f(0.90f, 0.96f, 1.0f);
    glBegin(GL_QUADS);

        glVertex3f(0.0, 21.0, 0.0);
        glColor3f(0.70f, 0.76f, 1.0f);
        glVertex3f(5.0, 16.0, 0.0);
       glColor3f(0.70f, 0.76f, 1.0f);
        glVertex3f(23.0, 16.0, 0.0);
        glColor3f(0.90f, 0.96f, 1.0f);
        glVertex3f(28.0, 21.0, 0.0);
    glEnd();
    //left side
    glColor3f(0.2f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
        glVertex3f(0.0, 21.0, 0.0);
        glColor3f(0.0f, 0.5f, 0.5f);
        glVertex3f(0.0, 0.0, 0.0);
        glColor3f(0.0f, 0.5f, 0.5f);
        glVertex3f(5.0, 5.0, 0.0);
        glColor3f(0.2f, 0.8f, 1.0f);
        glVertex3f(5.0, 16.0, 0.0);
    glEnd();

   //floor
        glColor3f(0.0f, 0.2f, 0.4f);
    glBegin(GL_QUADS);
        glVertex3f(0.0, 0.0, 0.0);
        glColor3f(0.1f, 0.3f, 0.5f);
        glVertex3f(28.0, 0.0, 0.0);
        glColor3f(0.1f, 0.3f, 0.5f);
        glVertex3f(23.0, 5.0, 0.0);
       glColor3f(0.0f, 0.2f, 0.4f);
        glVertex3f(5.0, 5.0, 0.0);
    glEnd();
    //right side
   glColor3f(0.2f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
        glVertex3f(23.0, 16.0, 0.0);
        glColor3f(0.0f, 0.5f, 0.5f);
        glVertex3f(23.0, 5.0, 0.0);
        glColor3f(0.0f, 0.5f, 0.5f);
        glVertex3f(28.0, 0.0, 0.0);
        glColor3f(0.2f, 0.8f, 1.0f);
        glVertex3f(28.0, 21.0, 0.0);
    glEnd();

}
void whiteboard()
{
    //board
   glColor3f(0.34f, 0.20f, 0.01f);
    glBegin(GL_QUADS);
        glVertex3f(6.5, 14.5, 0.0);
        glVertex3f(6.5, 9.5, 0.0);
        glVertex3f(18.5, 9.5, 0.0);
        glVertex3f(18.5, 14.5, 0.0);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex3f(7.0, 14.0, 0.0);
        glVertex3f(7.0, 10.0, 0.0);
        glVertex3f(18.0, 10.0, 0.0);
        glVertex3f(18.0, 14.0, 0.0);
    glEnd();

}
void left_window()
{
    //window
   glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex3f(0.0, 10.0, 0.0);
        glVertex3f(2.0, 11.0, 0.0);
        glVertex3f(2.0, 14.0, 0.0);
        glVertex3f(0.0, 15.0, 0.0);
    glEnd();
    glColor3f(0.34f, 0.20f, 0.01f);
    glBegin(GL_QUADS);
        glVertex3f(0.0, 10.0, 0.0);
        glVertex3f(2.0, 11.0, 0.0);
        glVertex3f(2.0, 11.2, 0.0);
        glVertex3f(0.0, 10.2, 0.0);
    glEnd();

    glColor3f(0.34f, 0.20f, 0.01f);
    glBegin(GL_QUADS);
        glVertex3f(2.0, 11.0, 0.0);
        glVertex3f(2.0, 14.0, 0.0);
        glVertex3f(1.8, 14.0, 0.0);
        glVertex3f(1.8, 11.0, 0.0);
    glEnd();

    glColor3f(0.34f, 0.20f, 0.01f);
    glBegin(GL_QUADS);
        glVertex3f(0.0, 15.0, 0.0);
        glVertex3f(0.0, 14.8, 0.0);
        glVertex3f(2, 13.8, 0.0);
        glVertex3f(2, 14.0, 0.0);
    glEnd();


    glColor3f(0.34f, 0.20f, 0.01f);
    glBegin(GL_QUADS);
        glVertex3f(1.1, 10.7, 0.0);
        glVertex3f(1.2, 10.8, 0.0);
        glVertex3f(1.2, 14.3, 0.0);
        glVertex3f(1.1, 14.2, 0.0);
    glEnd();

    glColor3f(0.34f, 0.20f, 0.01f);
    glBegin(GL_QUADS);
        glVertex3f(0.4, 10.2, 0.0);
        glVertex3f(0.5, 10.3, 0.0);
        glVertex3f(0.5, 14.8, 0.0);
        glVertex3f(0.4, 14.7, 0.0);
    glEnd();

}
void teacher_table()
{
        //teacher_table
    glColor3f(0.34f, 0.20f, 0.01f);
    glBegin(GL_QUADS);
        glVertex3f(6.0, 4.0, 0.0);
        glColor3f(0.64f, 0.40f, 0.08f);
        glVertex3f(7.0, 4.0, 0.0);
        glColor3f(0.64f, 0.40f, 0.08f);
        glVertex3f(7.0, 8.0, 0.0);
        glVertex3f(6.0, 8.0, 0.0);
    glEnd();
    glColor3f(0.34f, 0.20f, 0.01f);
    glBegin(GL_QUADS);
        glVertex3f(11.0, 4.0, 0.0);
        glColor3f(0.64f, 0.40f, 0.08f);
        glVertex3f(12.0, 4.0, 0.0);
        glColor3f(0.64f, 0.40f, 0.08f);
        glVertex3f(12.0, 8.0, 0.0);
        glVertex3f(11.0, 8.0, 0.0);
    glEnd();
    glColor3f(0.34f, 0.20f, 0.01f);
    glBegin(GL_QUADS);
        glColor3f(0.54f, 0.30f, 0.04f);
        glVertex3f(6.0, 8.0, 0.0);
        glColor3f(0.64f, 0.40f, 0.08f);
        glVertex3f(12.0, 8.0, 0.0);
        glColor3f(0.64f, 0.40f, 0.08f);
        glVertex3f(12.0, 9.0, 0.0);
        glVertex3f(6.0, 9.0, 0.0);
    glEnd();

}
void teacher()
{
    glPushMatrix();
    glTranslatef(tx,ty,0);
    glPushMatrix();
        glTranslatef(18.75,3.8,0);
        glColor3f(0.34f, 0.20f, 0.01f);
         circle(0.3,0.6);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(21.65,3.8,0);
        glColor3f(0.34f, 0.20f, 0.01f);
         circle(0.3,0.6);
    glPopMatrix();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(18.7, 3.8, 0.0);
        glVertex3f(19.0, 4.0, 0.0);
        glVertex3f(19.1, 5.0, 0.0);
        glVertex3f(19.3, 6.0, 0.0);
        glVertex3f(19.3, 6.5, 0.0);
        glVertex3f(19.5, 7.0, 0.0);
        glVertex3f(19.8, 8.0, 0.0);
        glVertex3f(20.0, 9.0, 0.0);
        glVertex3f(18.9, 9.0, 0.0);
        glVertex3f(18.7, 8.0, 0.0);
        glVertex3f(18.7, 7.0, 0.0);
        glVertex3f(18.7, 6.5, 0.0);
        glVertex3f(18.3, 6.0, 0.0);
        glVertex3f(18.5, 5.0, 0.0);
        glVertex3f(18.5, 4.0, 0.0);

    glEnd();
    //right_leg
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(21.5, 3.8, 0.0);
        glVertex3f(22.0, 4.0, 0.0);
        glVertex3f(21.8, 4.5, 0.0);
        glVertex3f(21.6, 5.0, 0.0);
        glVertex3f(21.6, 5.5, 0.0);
        glVertex3f(21.7, 6.0, 0.0);
        glVertex3f(21.5, 7.0, 0.0);
        glVertex3f(21.5, 8.0, 0.0);
        glVertex3f(21.4, 9.0, 0.0);
        glVertex3f(20.0, 9.0, 0.0);
        glVertex3f(20.2, 8.0, 0.0);
        glVertex3f(20.7, 7.0, 0.0);
        glVertex3f(20.8, 6.0, 0.0);
        glVertex3f(21.2, 5.0, 0.0);
        glVertex3f(21.4, 4.5, 0.0);
        glVertex3f(21.3, 4.0, 0.0);

    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(21.5, 8.5, 0.0);
        glVertex3f(21.2, 9.7, 0.0);
        glVertex3f(20.2, 9.5, 0.0);
        glVertex3f(20.5, 9.5, 0.0);
        glVertex3f(19.1, 9.7, 0.0);
        glVertex3f(18.8, 8.5, 0.0);
     glEnd();
    glPushMatrix();
    glRotatef(spinC2, 0.1, 1.0, 0.1);
      //body
     glColor3f(0.8f,1.0f, 0.90f);
    glBegin(GL_POLYGON);
        glVertex3f(20.2, 9.5, 0.0);
        glVertex3f(20.5, 9.5, 0.0);
        glVertex3f(21.2, 9.7, 0.0);
        glVertex3f(21.1, 10.2, 0.0);
        glVertex3f(21.3, 11.0, 0.0);
        glVertex3f(21.8, 12.0, 0.0);
        glVertex3f(20.3, 13.0, 0.0);
        glVertex3f(18.4, 12.0, 0.0);
        glVertex3f(18.9, 11.0, 0.0);
        glVertex3f(19.2, 10.2, 0.0);
        glVertex3f(19.1, 9.7, 0.0);
     glEnd();

    glColor3f(0.8f,1.0f, 0.90f);
    glBegin(GL_POLYGON);
        glVertex3f(21.8, 12.0, 0.0);
        glVertex3f(21.8, 12.4, 0.0);
        glVertex3f(21.0, 12.6, 0.0);
        glVertex3f(21.1, 10.2, 0.0);
        glVertex3f(20.6, 13.0, 0.0);
        glVertex3f(20.3, 13.0, 0.0);
        glVertex3f(20.0, 13.0, 0.0);
        glVertex3f(19.6, 12.6, 0.0);
        glVertex3f(18.4, 12.4, 0.0);
        glVertex3f(18.4, 12.0, 0.0);
     glEnd();

    //right hand
   glColor3f(0.8f,1.0f, 0.90f);
    glBegin(GL_POLYGON);

        glVertex3f(22.7, 9.0, 0.0);
        glVertex3f(21.8, 12.4, 0.0);
        glVertex3f(20.6, 12.8, 0.0);
        glVertex3f(22.1, 9.0, 0.0);

     glEnd();

     glColor3f(1.0f, 0.78f, 0.58f);
     glBegin(GL_POLYGON);

        glVertex3f(22.7, 8.5, 0.0);
        glVertex3f(22.7, 9.0, 0.0);
        glVertex3f(22.1, 9.0, 0.0);
        glVertex3f(22.1, 8.5, 0.0);

     glEnd();
     //left hand
     glColor3f(0.8f,1.0f, 0.90f);
    glBegin(GL_POLYGON);
        glVertex3f(18.3, 9.0, 0.0);
        glVertex3f(19.8, 12.8, 0.0);
        glVertex3f(18.3, 12.4, 0.0);
        glVertex3f(17.8, 9.0, 0.0);
     glEnd();
     glColor3f(1.0f, 0.78f, 0.58f);
     glBegin(GL_POLYGON);
        glVertex3f(18.3, 8.5, 0.0);
        glVertex3f(18.3, 9.0, 0.0);
        glVertex3f(17.8, 9.0, 0.0);
        glVertex3f(17.8, 8.5, 0.0);
     glEnd();
      glPopMatrix();

     //head
     glColor3f(1.0f, 0.78f, 0.58f);
     glBegin(GL_POLYGON);
        glVertex3f(20.6, 13.0, 0.0);
        glVertex3f(20.9, 13.2, 0.0);
        glVertex3f(20.9, 13.4, 0.0);
        glVertex3f(21.2, 14.5, 0.0);
        glVertex3f(21.3, 14.5, 0.0);
        glVertex3f(20.6, 15.0, 0.0);
        glVertex3f(20.3, 15.0, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.6, 14.5, 0.0);
        glVertex3f(19.7, 13.4, 0.0);
        glVertex3f(19.7, 13.2, 0.0);
        glVertex3f(20.0, 13.0, 0.0);
     glEnd();

     //hair
     glColor3f(0.0f, 0.0f, 0.0f);
     glBegin(GL_POLYGON);
        glVertex3f(21.2, 14.5, 0.0);
        glVertex3f(21.3, 14.5, 0.0);
        glVertex3f(20.6, 15.0, 0.0);
        glVertex3f(20.3, 15.0, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.6, 14.5, 0.0);
       glEnd();

       glPopMatrix();
}
void teacher_back()
{
    glPushMatrix();
    glTranslatef(tx1,ty1,0);

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(18.7, 3.8, 0.0);
        glVertex3f(19.0, 4.0, 0.0);
        glVertex3f(19.1, 5.0, 0.0);
        glVertex3f(19.3, 6.0, 0.0);
        glVertex3f(19.3, 6.5, 0.0);
        glVertex3f(19.5, 7.0, 0.0);
        glVertex3f(19.8, 8.0, 0.0);
        glVertex3f(20.0, 9.0, 0.0);
        glVertex3f(18.9, 9.0, 0.0);
        glVertex3f(18.7, 8.0, 0.0);
        glVertex3f(18.7, 7.0, 0.0);
        glVertex3f(18.7, 6.5, 0.0);
        glVertex3f(18.3, 6.0, 0.0);
        glVertex3f(18.5, 5.0, 0.0);
        glVertex3f(18.5, 4.0, 0.0);

    glEnd();
    //right_leg
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(21.5, 3.8, 0.0);
        glVertex3f(22.0, 4.0, 0.0);
        glVertex3f(21.8, 4.5, 0.0);
        glVertex3f(21.6, 5.0, 0.0);
        glVertex3f(21.6, 5.5, 0.0);
        glVertex3f(21.7, 6.0, 0.0);
        glVertex3f(21.5, 7.0, 0.0);
        glVertex3f(21.5, 8.0, 0.0);
        glVertex3f(21.4, 9.0, 0.0);
        glVertex3f(20.0, 9.0, 0.0);
        glVertex3f(20.2, 8.0, 0.0);
        glVertex3f(20.7, 7.0, 0.0);
        glVertex3f(20.8, 6.0, 0.0);
        glVertex3f(21.2, 5.0, 0.0);
        glVertex3f(21.4, 4.5, 0.0);
        glVertex3f(21.3, 4.0, 0.0);

    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(21.5, 8.5, 0.0);
        glVertex3f(21.2, 9.7, 0.0);
        glVertex3f(20.2, 9.5, 0.0);
        glVertex3f(20.5, 9.5, 0.0);
        glVertex3f(19.1, 9.7, 0.0);
        glVertex3f(18.8, 8.5, 0.0);
     glEnd();
    glPushMatrix();
    glRotatef(spinC2, 0.1, 1.0, 0.1);
      //body
     glColor3f(0.8f,1.0f, 0.90f);
    glBegin(GL_POLYGON);
        glVertex3f(20.2, 9.5, 0.0);
        glVertex3f(20.5, 9.5, 0.0);
        glVertex3f(21.2, 9.7, 0.0);
        glVertex3f(21.1, 10.2, 0.0);
        glVertex3f(21.3, 11.0, 0.0);
        glVertex3f(21.8, 12.0, 0.0);
        glVertex3f(20.3, 13.0, 0.0);
        glVertex3f(18.4, 12.0, 0.0);
        glVertex3f(18.9, 11.0, 0.0);
        glVertex3f(19.2, 10.2, 0.0);
        glVertex3f(19.1, 9.7, 0.0);
     glEnd();

    glColor3f(0.8f,1.0f, 0.90f);
    glBegin(GL_POLYGON);
        glVertex3f(21.8, 12.0, 0.0);
        glVertex3f(21.8, 12.4, 0.0);
        glVertex3f(21.0, 12.6, 0.0);
        glVertex3f(21.1, 10.2, 0.0);
        glVertex3f(20.6, 13.0, 0.0);
        glVertex3f(20.3, 13.0, 0.0);
        glVertex3f(20.0, 13.0, 0.0);
        glVertex3f(19.6, 12.6, 0.0);
        glVertex3f(18.4, 12.4, 0.0);
        glVertex3f(18.4, 12.0, 0.0);
     glEnd();

    //right hand
   glColor3f(0.8f,1.0f, 0.90f);
    glBegin(GL_POLYGON);

        glVertex3f(21.7, 12.3, 0.0);
        glVertex3f(21.7, 12.3, 0.0);
        glVertex3f(20.7, 12.2, 0.0);
        glVertex3f(20.7, 12.0, 0.0);

     glEnd();

     //left hand
     glColor3f(0.8f,1.0f, 0.90f);
    glBegin(GL_POLYGON);
        glVertex3f(18.3, 9.0, 0.0);
        glVertex3f(19.8, 12.8, 0.0);
        glVertex3f(18.3, 12.4, 0.0);
        glVertex3f(17.8, 9.0, 0.0);
     glEnd();
     glColor3f(1.0f, 0.78f, 0.58f);
     glBegin(GL_POLYGON);
        glVertex3f(18.3, 8.5, 0.0);
        glVertex3f(18.3, 9.0, 0.0);
        glVertex3f(17.8, 9.0, 0.0);
        glVertex3f(17.8, 8.5, 0.0);
     glEnd();

     //head
     glColor3f(0.0f, 0.0f, 0.0f);
     glBegin(GL_POLYGON);
        glVertex3f(20.6, 13.0, 0.0);
        glVertex3f(20.9, 13.2, 0.0);
        glVertex3f(20.9, 13.4, 0.0);
        glVertex3f(21.2, 14.5, 0.0);
        glVertex3f(21.3, 14.5, 0.0);
        glVertex3f(20.6, 15.0, 0.0);
        glVertex3f(20.3, 15.0, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.6, 14.5, 0.0);
        glVertex3f(19.7, 13.4, 0.0);
        glVertex3f(19.7, 13.2, 0.0);
        glVertex3f(20.0, 13.0, 0.0);
     glEnd();

     //hair
     glColor3f(0.0f, 0.0f, 0.0f);
     glBegin(GL_POLYGON);
        glVertex3f(21.2, 14.5, 0.0);
        glVertex3f(21.3, 14.5, 0.0);
        glVertex3f(20.6, 15.0, 0.0);
        glVertex3f(20.3, 15.0, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.6, 14.5, 0.0);
       glEnd();
       glPopMatrix();



       glPopMatrix();
}

void hair()
{
    glPushMatrix();
    glTranslatef(tx,ty,0);
      glPushMatrix();
        glTranslatef(19.7,14.5,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(19.9,14.5,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(20.1,14.5,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(19.7,14.6,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(19.9,14.7,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(20.1,14.7,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();



      glPushMatrix();
        glTranslatef(20.3,14.5,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(20.5,14.5,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(20.7,14.5,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(20.3,14.6,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(20.5,14.7,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(20.7,14.7,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

       glPushMatrix();
        glTranslatef(20.9,14.5,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(21.1,14.5,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(21.1,14.5,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(20.7,14.6,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(20.9,14.7,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(21.1,14.7,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.2,0.2);
      glPopMatrix();

       glPopMatrix();




}
void mouth()
{


    glPushMatrix();
    glTranslatef(tx,ty,0);
    glRotatef(spinC2, -0.1, -1.0, -0.1);
    glColor3f(0.0f, 0.0f, 0.0f);
     glBegin(GL_QUADS);
        glVertex3f(20.55, 13.3, 0.0);
        glVertex3f(20.55, 13.4, 0.0);
        glVertex3f(20.05, 13.4, 0.0);
        glVertex3f(20.05, 13.3, 0.0);
    glEnd();
    //nose
    glColor3f(0.0f, 0.0f, 0.0f);
     glBegin(GL_QUADS);
        glVertex3f(20.45, 13.6, 0.0);
        glVertex3f(20.45, 13.7, 0.0);
        glVertex3f(20.25, 13.7, 0.0);
        glVertex3f(20.25, 13.6, 0.0);
    glEnd();
    glPopMatrix();
}
void eye()
{

    glPushMatrix();
    glTranslatef(tx,ty,0);
         glPushMatrix();
         glTranslatef(-0.5,0.5,0);
         glColor3f(0.0f, 0.0f, 0.0f);
         glBegin(GL_QUADS);
         glVertex3f(20.60, 13.6, 0.0);
         glVertex3f(20.60, 13.7, 0.0);
         glVertex3f(20.25, 13.7, 0.0);
         glVertex3f(20.25, 13.6, 0.0);
         glEnd();
         glPopMatrix();

         glPushMatrix();
         glTranslatef(0.2,0.5,0);
         glColor3f(0.0f, 0.0f, 0.0f);
         glBegin(GL_QUADS);
         glVertex3f(20.60, 13.6, 0.0);
         glVertex3f(20.60, 13.7, 0.0);
         glVertex3f(20.25, 13.7, 0.0);
         glVertex3f(20.25, 13.6, 0.0);
         glEnd();
         glPopMatrix();

        glPushMatrix();

         //glRotatef(e, 0, 0, 1);
        glPushMatrix();
        glTranslatef(19.95,14,0);
        glColor3f(1.0f, 1.0f, 1.0f);
         circle(0.2,0.1);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(19.95,14,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.1,0.1);
        glPopMatrix();

         glPushMatrix();
        glTranslatef(20.6,14,0);
        glColor3f(1.0f, 1.0f, 1.0f);
         circle(0.2,0.1);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(20.6,14,0);
        glColor3f(0.0f, 0.0f, 0.0f);
         circle(0.1,0.1);
        glPopMatrix();

         glPopMatrix();

     glPopMatrix();
}

void student(int tx,int ty,float a,float b,float c)
{
    glPushMatrix();
    glTranslatef(tx,ty,0);
    glRotatef(spinC2, a, b, c);

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(18.7, 3.8, 0.0);
        glVertex3f(19.0, 4.0, 0.0);
        glVertex3f(19.1, 5.0, 0.0);
        glVertex3f(19.3, 6.0, 0.0);
        glVertex3f(19.3, 6.5, 0.0);
        glVertex3f(19.5, 7.0, 0.0);
        glVertex3f(19.8, 8.0, 0.0);
        glVertex3f(20.0, 9.0, 0.0);
        glVertex3f(18.9, 9.0, 0.0);
        glVertex3f(18.7, 8.0, 0.0);
        glVertex3f(18.7, 7.0, 0.0);
        glVertex3f(18.7, 6.5, 0.0);
        glVertex3f(18.3, 6.0, 0.0);
        glVertex3f(18.5, 5.0, 0.0);
        glVertex3f(18.5, 4.0, 0.0);

    glEnd();
    //right_leg
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(21.5, 3.8, 0.0);
        glVertex3f(22.0, 4.0, 0.0);
        glVertex3f(21.8, 4.5, 0.0);
        glVertex3f(21.6, 5.0, 0.0);
        glVertex3f(21.6, 5.5, 0.0);
        glVertex3f(21.7, 6.0, 0.0);
        glVertex3f(21.5, 7.0, 0.0);
        glVertex3f(21.5, 8.0, 0.0);
        glVertex3f(21.4, 9.0, 0.0);
        glVertex3f(20.0, 9.0, 0.0);
        glVertex3f(20.2, 8.0, 0.0);
        glVertex3f(20.7, 7.0, 0.0);
        glVertex3f(20.8, 6.0, 0.0);
        glVertex3f(21.2, 5.0, 0.0);
        glVertex3f(21.4, 4.5, 0.0);
        glVertex3f(21.3, 4.0, 0.0);

    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(21.5, 8.5, 0.0);
        glVertex3f(21.2, 9.7, 0.0);
        glVertex3f(20.2, 9.5, 0.0);
        glVertex3f(20.5, 9.5, 0.0);
        glVertex3f(19.1, 9.7, 0.0);
        glVertex3f(18.8, 8.5, 0.0);
     glEnd();

      //body
     glColor3f(0.768f,0.741f,0.737f);
    glBegin(GL_POLYGON);
        glVertex3f(20.2, 9.5, 0.0);
        glVertex3f(20.5, 9.5, 0.0);
        glVertex3f(21.2, 9.7, 0.0);
        glVertex3f(21.1, 10.2, 0.0);
        glVertex3f(21.3, 11.0, 0.0);
        glVertex3f(21.8, 12.0, 0.0);
        glVertex3f(20.3, 13.0, 0.0);
        glVertex3f(18.4, 12.0, 0.0);
        glVertex3f(18.9, 11.0, 0.0);
        glVertex3f(19.2, 10.2, 0.0);
        glVertex3f(19.1, 9.7, 0.0);
     glEnd();

    glColor3f(0.768f,0.741f,0.737f);
    glBegin(GL_POLYGON);
        glVertex3f(21.8, 12.0, 0.0);
        glVertex3f(21.8, 12.4, 0.0);
        glVertex3f(21.0, 12.6, 0.0);
        glVertex3f(21.1, 10.2, 0.0);
        glVertex3f(20.6, 13.0, 0.0);
        glVertex3f(20.3, 13.0, 0.0);
        glVertex3f(20.0, 13.0, 0.0);
        glVertex3f(19.6, 12.6, 0.0);
        glVertex3f(18.4, 12.4, 0.0);
        glVertex3f(18.4, 12.0, 0.0);
     glEnd();

    //right hand
    glColor3f(0.768f,0.741f,0.737f);
    glBegin(GL_POLYGON);

        glVertex3f(22.7, 9.0, 0.0);
        glVertex3f(21.8, 12.4, 0.0);
        glVertex3f(20.6, 12.8, 0.0);
        glVertex3f(22.1, 9.0, 0.0);

     glEnd();

     glColor3f(0.768f,0.741f,0.737f);
     glBegin(GL_POLYGON);

        glVertex3f(22.7, 8.5, 0.0);
        glVertex3f(22.7, 9.0, 0.0);
        glVertex3f(22.1, 9.0, 0.0);
        glVertex3f(22.1, 8.5, 0.0);

     glEnd();
     //left hand
     glColor3f(0.768f,0.741f,0.737f);
    glBegin(GL_POLYGON);
        glVertex3f(18.3, 9.0, 0.0);
        glVertex3f(19.8, 12.8, 0.0);
        glVertex3f(18.3, 12.4, 0.0);
        glVertex3f(17.8, 9.0, 0.0);
     glEnd();
     glColor3f(1.0f, 0.78f, 0.58f);
     glBegin(GL_POLYGON);
        glVertex3f(18.3, 8.5, 0.0);
        glVertex3f(18.3, 9.0, 0.0);
        glVertex3f(17.8, 9.0, 0.0);
        glVertex3f(17.8, 8.5, 0.0);
     glEnd();

     //head
     glColor3f(0.0f, 0.0f, 0.0f);
     glBegin(GL_POLYGON);
        glVertex3f(20.6, 13.0, 0.0);
        glVertex3f(20.9, 13.2, 0.0);
        glVertex3f(20.9, 13.4, 0.0);
        glVertex3f(21.2, 14.5, 0.0);
        glVertex3f(21.3, 14.5, 0.0);
        glVertex3f(20.6, 15.0, 0.0);
        glVertex3f(20.3, 15.0, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.6, 14.5, 0.0);
        glVertex3f(19.7, 13.4, 0.0);
        glVertex3f(19.7, 13.2, 0.0);
        glVertex3f(20.0, 13.0, 0.0);
     glEnd();

     //hair
     glColor3f(0.0f, 0.0f, 0.0f);
     glBegin(GL_POLYGON);
        glVertex3f(21.2, 14.5, 0.0);
        glVertex3f(21.3, 14.5, 0.0);
        glVertex3f(20.6, 15.0, 0.0);
        glVertex3f(20.3, 15.0, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.6, 14.5, 0.0);
       glEnd();

       glPopMatrix();
}

void student_new(int tx,int ty,float a,float b,float c)
{
   glPushMatrix();
   glTranslatef(sx,sy,0);
    glPushMatrix();
    glTranslatef(tx,ty,0);
    glRotatef(spinC2, a, b, c);

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(18.7, 3.8, 0.0);
        glVertex3f(19.0, 4.0, 0.0);
        glVertex3f(19.1, 5.0, 0.0);
        glVertex3f(19.3, 6.0, 0.0);
        glVertex3f(19.3, 6.5, 0.0);
        glVertex3f(19.5, 7.0, 0.0);
        glVertex3f(19.8, 8.0, 0.0);
        glVertex3f(20.0, 9.0, 0.0);
        glVertex3f(18.9, 9.0, 0.0);
        glVertex3f(18.7, 8.0, 0.0);
        glVertex3f(18.7, 7.0, 0.0);
        glVertex3f(18.7, 6.5, 0.0);
        glVertex3f(18.3, 6.0, 0.0);
        glVertex3f(18.5, 5.0, 0.0);
        glVertex3f(18.5, 4.0, 0.0);

    glEnd();
    //right_leg
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(21.5, 3.8, 0.0);
        glVertex3f(22.0, 4.0, 0.0);
        glVertex3f(21.8, 4.5, 0.0);
        glVertex3f(21.6, 5.0, 0.0);
        glVertex3f(21.6, 5.5, 0.0);
        glVertex3f(21.7, 6.0, 0.0);
        glVertex3f(21.5, 7.0, 0.0);
        glVertex3f(21.5, 8.0, 0.0);
        glVertex3f(21.4, 9.0, 0.0);
        glVertex3f(20.0, 9.0, 0.0);
        glVertex3f(20.2, 8.0, 0.0);
        glVertex3f(20.7, 7.0, 0.0);
        glVertex3f(20.8, 6.0, 0.0);
        glVertex3f(21.2, 5.0, 0.0);
        glVertex3f(21.4, 4.5, 0.0);
        glVertex3f(21.3, 4.0, 0.0);

    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(21.5, 8.5, 0.0);
        glVertex3f(21.2, 9.7, 0.0);
        glVertex3f(20.2, 9.5, 0.0);
        glVertex3f(20.5, 9.5, 0.0);
        glVertex3f(19.1, 9.7, 0.0);
        glVertex3f(18.8, 8.5, 0.0);
     glEnd();

      //body
     glColor3f(0.768f,0.741f,0.737f);
    glBegin(GL_POLYGON);
        glVertex3f(20.2, 9.5, 0.0);
        glVertex3f(20.5, 9.5, 0.0);
        glVertex3f(21.2, 9.7, 0.0);
        glVertex3f(21.1, 10.2, 0.0);
        glVertex3f(21.3, 11.0, 0.0);
        glVertex3f(21.8, 12.0, 0.0);
        glVertex3f(20.3, 13.0, 0.0);
        glVertex3f(18.4, 12.0, 0.0);
        glVertex3f(18.9, 11.0, 0.0);
        glVertex3f(19.2, 10.2, 0.0);
        glVertex3f(19.1, 9.7, 0.0);
     glEnd();

    glColor3f(0.768f,0.741f,0.737f);
    glBegin(GL_POLYGON);
        glVertex3f(21.8, 12.0, 0.0);
        glVertex3f(21.8, 12.4, 0.0);
        glVertex3f(21.0, 12.6, 0.0);
        glVertex3f(21.1, 10.2, 0.0);
        glVertex3f(20.6, 13.0, 0.0);
        glVertex3f(20.3, 13.0, 0.0);
        glVertex3f(20.0, 13.0, 0.0);
        glVertex3f(19.6, 12.6, 0.0);
        glVertex3f(18.4, 12.4, 0.0);
        glVertex3f(18.4, 12.0, 0.0);
     glEnd();

    //right hand
    glColor3f(0.768f,0.741f,0.737f);
    glBegin(GL_POLYGON);

        glVertex3f(22.7, 9.0, 0.0);
        glVertex3f(21.8, 12.4, 0.0);
        glVertex3f(20.6, 12.8, 0.0);
        glVertex3f(22.1, 9.0, 0.0);

     glEnd();

     glColor3f(0.768f,0.741f,0.737f);
     glBegin(GL_POLYGON);

        glVertex3f(22.7, 8.5, 0.0);
        glVertex3f(22.7, 9.0, 0.0);
        glVertex3f(22.1, 9.0, 0.0);
        glVertex3f(22.1, 8.5, 0.0);

     glEnd();
     //left hand
     glColor3f(0.768f,0.741f,0.737f);
    glBegin(GL_POLYGON);
        glVertex3f(18.3, 9.0, 0.0);
        glVertex3f(19.8, 12.8, 0.0);
        glVertex3f(18.3, 12.4, 0.0);
        glVertex3f(17.8, 9.0, 0.0);
     glEnd();
     glColor3f(1.0f, 0.78f, 0.58f);
     glBegin(GL_POLYGON);
        glVertex3f(18.3, 8.5, 0.0);
        glVertex3f(18.3, 9.0, 0.0);
        glVertex3f(17.8, 9.0, 0.0);
        glVertex3f(17.8, 8.5, 0.0);
     glEnd();

     //head
     glColor3f(0.0f, 0.0f, 0.0f);
     glBegin(GL_POLYGON);
        glVertex3f(20.6, 13.0, 0.0);
        glVertex3f(20.9, 13.2, 0.0);
        glVertex3f(20.9, 13.4, 0.0);
        glVertex3f(21.2, 14.5, 0.0);
        glVertex3f(21.3, 14.5, 0.0);
        glVertex3f(20.6, 15.0, 0.0);
        glVertex3f(20.3, 15.0, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.6, 14.5, 0.0);
        glVertex3f(19.7, 13.4, 0.0);
        glVertex3f(19.7, 13.2, 0.0);
        glVertex3f(20.0, 13.0, 0.0);
     glEnd();

     //hair
     glColor3f(0.0f, 0.0f, 0.0f);
     glBegin(GL_POLYGON);
        glVertex3f(21.2, 14.5, 0.0);
        glVertex3f(21.3, 14.5, 0.0);
        glVertex3f(20.6, 15.0, 0.0);
        glVertex3f(20.3, 15.0, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.4, 14.5, 0.0);
        glVertex3f(19.6, 14.5, 0.0);
       glEnd();

       glPopMatrix();
    glPopMatrix();
}

void student_table()
{
     glColor3f(0.34f, 0.20f, 0.01f);
    glBegin(GL_QUADS);
        glVertex3f(0.0, 1.0, 0.0);
        glColor3f(0.64f, 0.40f, 0.08f);
        glVertex3f(19.0, 1.0, 0.0);
        glColor3f(0.64f, 0.40f, 0.08f);
        glVertex3f(18.0, 3.0, 0.0);
        glVertex3f(2.0, 3.0, 0.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(0.0, 0.8, 0.0);
        glVertex3f(19.0, 0.8, 0.0);
        glVertex3f(19.0, 1.0, 0.0);
        glVertex3f(0.0, 1.0, 0.0);
    glEnd();
    glColor3f(0.34f, 0.20f, 0.01f);
    glBegin(GL_QUADS);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(1.0, 0.0, 0.0);
        glVertex3f(1.0, 0.8, 0.0);
        glVertex3f(0.0, 0.8, 0.0);
    glEnd();
    glColor3f(0.34f, 0.20f, 0.01f);
    glBegin(GL_QUADS);
        glVertex3f(18.0, 0.0, 0.0);
        glVertex3f(19.0, 0.0, 0.0);
        glVertex3f(19.0, 0.8, 0.0);
        glVertex3f(18.0, 0.8, 0.0);
    glEnd();
}
void fan()
{

   glColor3f(0.0f, 0.2f, 0.4f);
    glBegin(GL_QUADS);
        glVertex3f(16.0, 20.0, 0.0);
        glColor3f(0.1f, 0.3f, 0.5f);
        glVertex3f(16.0, 21.0, 0.0);
        glColor3f(0.1f, 0.3f, 0.5f);
        glVertex3f(15.0, 21.0, 0.0);
        glVertex3f(15.0, 20.0, 0.0);
    glEnd();


    glPushMatrix();
    glTranslatef(15.5,19.5,0.0);

	glRotatef(spin, 0.0, 1.0, 0.0);//y axis er shapekkhe so y=1 set kora
    glColor3f(0.0f, 0.2f, 0.4f);
    glBegin(GL_QUADS);
        glVertex3f(18.0-15.5, 19.7-19.5, 0.0);
        glVertex3f(18.0-15.5, 20.0-19.5, 0.0);
        glVertex3f(13.0-15.5, 20.0-19.5, 0.0);
        glVertex3f(13.0-15.5, 19.7-19.5, 0.0);
    glEnd();

    glColor3f(0.0f, 0.2f, 0.4f);
    glBegin(GL_QUADS);
        glVertex3f(15.8-15.5, 19.4-19.5, 0.0);
        glVertex3f(15.8-15.5, 20.0-19.5, 0.0);
        glVertex3f(15.2-15.5, 20.0-19.5, 0.0);
        glVertex3f(15.2-15.5, 19.4-19.5, 0.0);
    glEnd();


	glPopMatrix();


}
void clock()
{
    glPushMatrix();

    glTranslatef(21.5,14.0,0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    circle(1,1);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.8,0.8);
    glPopMatrix();

}
void clock_element()
{
    glPushMatrix();
    glTranslatef(21.5,14.0,0.0);
    glRotatef(spinC, 0.0, 0.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
     glBegin(GL_QUADS);
        glVertex3f(22.3-21.5, 14.0-14.0, 0.0);
        glVertex3f(22.3-21.5, 14.1-14.0, 0.0);
        glVertex3f(21.45-21.5, 14.1-14.0, 0.0);
        glVertex3f(21.45-21.5, 14.0-14.0, 0.0);
    glEnd();
     glPopMatrix();
}
void clock_element1()
{
    glPushMatrix();
    glTranslatef(21.5,14.0,0.0);
    glRotatef(spinC1, 0.0, 0.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
     glBegin(GL_QUADS);
        glVertex3f(22.2-21.5, 14.0-14.0, 0.0);
        glVertex3f(22.2-21.5, 14.1-14.0, 0.0);
        glVertex3f(21.45-21.5, 14.1-14.0, 0.0);
        glVertex3f(21.45-21.5, 14.0-14.0, 0.0);
    glEnd();
     glPopMatrix();
}
void whiteboard_o()
{
    glPushMatrix();
    glTranslatef(ox,oy,0);

    glPushMatrix();
    glTranslatef(8.0,12.5,0.0);
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.8,0.8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.5,0.5);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}
void whiteboard_p()
{
    glPushMatrix();
    glTranslatef(px,py,0);

    glPushMatrix();
    glTranslatef(9.5,13.0,0.0);
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.7,0.7);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.4,0.4);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.7,4.5,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(16.0-9.5, 20.0-13, 0.0);
        glVertex3f(16.0-9.5, 22.0-13, 0.0);
        glVertex3f(15.6-9.5, 22.0-13, 0.0);
        glVertex3f(15.6-9.5, 20.0-13, 0.0);
    glEnd();
    glPopMatrix();


    glPopMatrix();
}
void whiteboard_e()
{
    glPushMatrix();
    glTranslatef(ex,ey,0);

    glPushMatrix();
    glTranslatef(4.0,4.5,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(16.0-9.5, 20.0-13, 0.0);
        glVertex3f(16.0-9.5, 22.0-13, 0.0);
        glVertex3f(15.6-9.5, 22.0-13, 0.0);
        glVertex3f(15.6-9.5, 20.0-13, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.0,4.5,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(16.6-9.5, 20.0-13, 0.0);
        glVertex3f(16.6-9.5, 20.4-13, 0.0);
        glVertex3f(15.6-9.5, 20.4-13, 0.0);
        glVertex3f(15.6-9.5, 20.0-13, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.0,5.3,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(16.6-9.5, 20.0-13, 0.0);
        glVertex3f(16.6-9.5, 20.4-13, 0.0);
        glVertex3f(15.6-9.5, 20.4-13, 0.0);
        glVertex3f(15.6-9.5, 20.0-13, 0.0);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(4.0,6.1,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(16.6-9.5, 20.0-13, 0.0);
        glVertex3f(16.6-9.5, 20.4-13, 0.0);
        glVertex3f(15.6-9.5, 20.4-13, 0.0);
        glVertex3f(15.6-9.5, 20.0-13, 0.0);
    glEnd();
    glPopMatrix();


    glPopMatrix();
}

void whiteboard_n()
{
    glPushMatrix();
    glTranslatef(nx,ny,0);

    glPushMatrix();
    glTranslatef(5.5,4.5,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(16.0-9.5, 20.0-13, 0.0);
        glVertex3f(16.0-9.5, 22.0-13, 0.0);
        glVertex3f(15.6-9.5, 22.0-13, 0.0);
        glVertex3f(15.6-9.5, 20.0-13, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.3,4.5,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(16.0-9.5, 20.0-13, 0.0);
        glVertex3f(16.0-9.5, 22.0-13, 0.0);
        glVertex3f(15.6-9.5, 22.0-13, 0.0);
        glVertex3f(15.6-9.5, 20.0-13, 0.0);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(12.0,11.3,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(0.9, 0.2, 0.0);
        glVertex3f(0, 2, 0.0);
        glVertex3f(0, 1.4, 0.0);
        glVertex3f(0.5, 0.2, 0.0);
    glEnd();
    glPopMatrix();


    glPopMatrix();


}
void whiteboard_g()
{
    glPushMatrix();
    glTranslatef(gx,gy,0);

    glPushMatrix();
    glTranslatef(14.0,12.5,0.0);
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.8,0.8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.5,0.5);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8.3,4.5,0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex3f(16.0-9.5, 20.0-13, 0.0);
        glVertex3f(16.0-9.5, 22.0-13, 0.0);
        glVertex3f(15.6-9.5, 22.0-13, 0.0);
        glVertex3f(15.6-9.5, 20.0-13, 0.0);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(7.7,4.9,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(16.4-9.5, 20.0-13, 0.0);
        glVertex3f(16.4-9.5, 20.4-13, 0.0);
        glVertex3f(15.6-9.5, 20.4-13, 0.0);
        glVertex3f(15.6-9.5, 20.0-13, 0.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(16.4-9.5, 19.6-13, 0.0);
        glVertex3f(16.4-9.5, 20.4-13, 0.0);
        glVertex3f(16.1-9.5, 20.4-13, 0.0);
        glVertex3f(16.1-9.5, 19.6-13, 0.0);
    glEnd();

    glPopMatrix();

    glPopMatrix();

}
void whiteboard_l()
{
    glPushMatrix();
    glTranslatef(lx,ly,0);

    glPushMatrix();
    glTranslatef(9.0,4.5,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(16.0-9.5, 20.0-13, 0.0);
        glVertex3f(16.0-9.5, 22.0-13, 0.0);
        glVertex3f(15.6-9.5, 22.0-13, 0.0);
        glVertex3f(15.6-9.5, 20.0-13, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9.0,4.5,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(16.6-9.5, 20.0-13, 0.0);
        glVertex3f(16.6-9.5, 20.4-13, 0.0);
        glVertex3f(15.6-9.5, 20.4-13, 0.0);
        glVertex3f(15.6-9.5, 20.0-13, 0.0);
    glEnd();
    glPopMatrix();


    glPopMatrix();

}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    classroom();
    whiteboard();
    whiteboard_o();
    whiteboard_p();
    whiteboard_e();
    whiteboard_n();
    whiteboard_g();
    whiteboard_l();
    left_window();
    teacher_table();
    clock();
    clock_element();

    clock_element1();

    teacher();
    mouth();
    eye();
    hair();
    teacher_back();
    student_table();
    student(-5,-10,-0.1, 1.0, -0.1);
    student(-10,-10,0.1, 0.8, -0.1);
    student_new(-15,-10,-0.2, 1.0,  0.1);

    fan();





    glutIdleFunc(spinDisplay_right);
    glFlush();
}
void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:
				tx -=2;
				tx1 -=2;

				glutPostRedisplay();
				break;

		case GLUT_KEY_RIGHT:
				tx +=2;
				tx1 +=2;
				glutPostRedisplay();
				break;

        case GLUT_KEY_DOWN:
				//ty -=2;
				//ty1 -=2;

				glutPostRedisplay();
				break;

		case GLUT_KEY_UP:
				//ty +=2;
				//ty1 +=2;


				glutPostRedisplay();
				break;
	  default:
			break;
	}
}
void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)//mouse press detected
           PlaySound("query.wav", NULL, SND_FILENAME| SND_ASYNC);
         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
          PlaySound("teacher_intro.wav", NULL, SND_FILENAME| SND_ASYNC);
         break;
      default:
         break;
   }
}


int main()
{

    glutInitWindowSize(800,650);
    glutInitWindowPosition(200,100);
    glutCreateWindow("srz");
    init();
    glutDisplayFunc(myDisplay);
    glutMouseFunc(my_mouse);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(my_keyboard);
    glutMainLoop();
    return 0;
}
