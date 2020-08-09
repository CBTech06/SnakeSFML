/* copyright (c) 2017 bourgeois christophe
permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "software"), to deal
in the software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the software, and to permit persons to whom the software is
furnished to do so, subject to the following conditions:
the above copyright notice and this permission notice shall be included in all
copies or substantial portions of the software.
the software is provided "as is", without warranty of any kind, express or
implied, including but not limited to the warranties of merchantability,
fitness for a particular purpose and noninfringement. in no event shall the
authors or copyright holders be liable for any claim, damages or other
lIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.#include "boat.hpp"
*/

#include "snake.hpp"
#include "pills.hpp"
#include "board.hpp"

float gameSpeed(0.2);

int main(int argc, char *argv[])
{
  std::srand(time(NULL));
  sf::RenderWindow window(sf::VideoMode(320,480),"SFML GameDev",sf::Style::Resize);
  
  Board board;
  board.load();
  
  Pills pills;
  Snake snake[100];
  sf::Clock clock;
 
  while(window.isOpen())
    {
      sf::Event event;
  
      while(window.pollEvent(event))
	{
	  if((event.type == event.KeyPressed && event.key.code == sf::Keyboard::Escape)
	     || (event.type == event.Closed))
	    window.close();
	}
      
      // Spawn Pills and move Snake
      if(clock.getElapsedTime().asSeconds() >= gameSpeed)
	{
	  snake[0].move();
	  clock.restart();
	  
	    for (int idx = snake[0].returnSnakeParts(); idx > 0;--idx)
	      {
		snake[idx].moveTail(snake[idx-1].getPosition());
	      }
	    
	    snake[0].checkTreeCollision(board.collisionInfo());
	    pills.checkCollision(board.collisionInfo());
	    snake[0].updatePosition();
	}
      
      for(int i = 1; i < snake[0].returnSnakeParts(); ++i)
	{
	  snake[0].checkCollision(snake[i].getPosition(),i);
	}
      
      window.clear(sf::Color::White);
      board.show(window);
      snake[0].eatPills(pills.spawn(),pills,gameSpeed);
      pills.draw(window);

      for(int i=0; i < snake[0].returnSnakeParts();i++) { snake[i].draw(window); }
      window.display();
    }
  
  return 0;
}

