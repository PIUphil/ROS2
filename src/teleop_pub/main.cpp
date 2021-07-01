#include "TeleopPub.h"
//#include <stdio.h>  
#include <iostream>
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
  // Rclcpp::spin(std::make_shared<TeleopPub>());
  std::shared_ptr<TeleopPub> teleopPub = std::make_shared<TeleopPub>();
     

  for(;;)
  {
    std::cout << "input key(i,m,j,l,s,q): ";
    char ch;
    ch = getch();
  

    switch(ch)
    {
    case 'i': case 'I':
      teleopPub->forward(); 
      break;
    case 'm': case 'M':
      teleopPub->backward(); 
      break;
    case 'j': case 'J':
      teleopPub->rotateLeft(); 
      break;
    case 'l': case 'L':
      teleopPub->rotateRight(); 
      break;
    case 's': case 'S':
      teleopPub->stop();
      break;
    case 'q': case 'Q':
      teleopPub->stop();
      goto out;
      break;
    }
  }

  out:

  rclcpp::shutdown();

  return 0;
}
