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

Snake::Snake(): window_x(0),window_y(0),window_width(320),window_height(480)
{
  if(!texture.loadFromFile("Ressources/red.png"))
    std::cout << "Error loading file" << std::endl;
  direction = NONE;
  sprite.setTexture(texture);
  parts = 1;
  position.x = 2;
  position.y = 4;
  sprite.setPosition(position.x,position.y);
  speed = 1;
  oldParts = 1;
}

sf::Vector2f Snake::move()
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != DOWN)
    direction = UP;
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != UP)
    direction = DOWN;
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != RIGHT)
    direction = LEFT;
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != LEFT)
    direction = RIGHT;
}


void Snake::eatPills(const sf::Vector2f& pillsPosition,Pills& p,float& gameSpeed)
{
  if(sprite.getPosition().x == pillsPosition.x &&
     sprite.getPosition().y == pillsPosition.y)
    {
      ++parts;
      p.respawn();
    }
  
  // Speed up the snake
  if (parts %3 == 0)
    {
      if(parts != oldParts) { gameSpeed -= 0.02; }
      oldParts = parts;
    }
}

void Snake::checkTreeCollision(const std::vector<sf::FloatRect>& block)
{
  collision = NONE;
 
  for(int i=0;i<block.size();i++)
    {
      // Left / Right Collision
      if(sprite.getGlobalBounds().contains(block[i].left - TILE_SIZE,block[i].top)
	 || sprite.getGlobalBounds().contains(block[i].left - TILE_SIZE,block[i].top + TILE_SIZE))
	{
	  collision = LEFT;
	}
      
      if(sprite.getGlobalBounds().contains(block[i].left + block[i].width,block[i].top)
	      || sprite.getGlobalBounds().contains(block[i].left + block[i].width,block[i].top + TILE_SIZE))
	{
	  collision = RIGHT;
	}

      // Top / Bottom Collision
      if(sprite.getGlobalBounds().contains(block[i].left,block[i].top - TILE_SIZE)
	 || sprite.getGlobalBounds().contains(block[i].left + TILE_SIZE,block[i].top - TILE_SIZE))
	{
	  collision = UP;
	}
      if(sprite.getGlobalBounds().contains(block[i].left,(block[i].top + block[i].height))
	      || sprite.getGlobalBounds().contains((block[i].left + TILE_SIZE),
						   (block[i].top + block[i].height)))
	{
	  collision = DOWN;
	}
      }
  
  
}

void Snake::updatePosition()
{
  if (direction == UP && collision != DOWN)
    position.y -= speed;
  if(direction == DOWN && collision != UP)
    position.y += speed;
  if(direction == LEFT && collision != RIGHT)
    position.x -= speed;
  if(direction == RIGHT && collision != LEFT)
    position.x += speed;

  if(sprite.getPosition().y < window_y) {position.y = 30;}
  else if(sprite.getPosition().y > window_height) { position.y = window_y;}
  if(sprite.getPosition().x < window_x) { position.x = 20;}
  else if(sprite.getPosition().x > window_width) { position.x = window_x;}

  sprite.setPosition(position.x * TILE_SIZE,position.y * TILE_SIZE);
}

void Snake::moveTail(const sf::Vector2f& headPosition)
{
  position.x = headPosition.x;
  position.y = headPosition.y;
  
  sprite.setPosition(position.x* TILE_SIZE,position.y*TILE_SIZE);
}

void Snake::checkCollision(const sf::Vector2f& tailPosition,const int&tailParts)
{
  if(tailPosition.x == sprite.getPosition().x  / TILE_SIZE &&
     tailPosition.y == sprite.getPosition().y  / TILE_SIZE)
    {
      parts = tailParts;
    }
}

void Snake::draw(sf::RenderWindow& win)
{
  
  win.draw(sprite);
}
