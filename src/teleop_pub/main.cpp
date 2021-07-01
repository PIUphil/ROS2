#include "teleopPub.h"
#include <stdio.h>  
// #include <term.h>
#include <termios.h>  
#include <unistd.h>


int getch(void)  
{
  int chr;  
  struct termios buf, save;  
  
  tcgetattr(0, &save);  
  buf = save;  
  buf.c_lflag &= ~(ICANON|ECHO);  
  buf.c_cc[VMIN] = 1;  
  buf.c_cc[VTIME] = 0;  
  tcsetattr(0, TCSAFLUSH, &buf);  
  chr = getchar();  
  tcsetattr(0, TCSAFLUSH, &save);  
  return chr;
}


int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  
  std::shared_ptr<teleopPub> teleoppub = std::make_shared<teleopPub>();
     

  for(;;)
  {
    std::cout << "input key(i,m,j,l,s): ";
    char ch;
    ch = getch();
  
  
    switch(ch)
    {
    case 'i': case 'I':
      teleoppub->forward(); 
      break;
    case 'm': case 'M':
      teleoppub->backward(); 
      break;
    case 'j': case 'J':
      teleoppub->rotateLeft(); 
      break;
    case 'l': case 'L':
      teleoppub->rotateRight(); 
      break;
    case 's': case 'S':
      teleoppub->stop();
      break;
    }
  }

  rclcpp::shutdown();

  return 0;
}