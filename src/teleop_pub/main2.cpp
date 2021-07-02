#include "TeleopPub.h"
#include <iostream>
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
    std::cout << "input key(i,m,j,k/s,q): ";
    char ch;
    ch = getch();
  

    switch(ch)
    {
    case 'i': case 'I':
      teleopPub->move(TeleopPub::DIRECTION_FORWARD); 
      break;
    case 'm': case 'M':
      teleopPub->move(TeleopPub::DIRECTION_BACKWARD); 
      break;
    case 'j': case 'J':
      teleopPub->move(TeleopPub::ROTATE_LEFT); 
      break;
    case 'k': case 'K':
      teleopPub->move(TeleopPub::ROTATE_RIGHT); 
      break;
    case 's': case 'S':
      teleopPub->move(TeleopPub::DIRECTION_STOP);
      break;
    case 'q': case 'Q':
      teleopPub->move(TeleopPub::DIRECTION_STOP);
      goto out;
      break;
    }
  }

  out:

  rclcpp::shutdown();

  return 0;
}
