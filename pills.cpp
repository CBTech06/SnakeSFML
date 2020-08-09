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

#include "pills.hpp"

Pills::Pills()
{
  rect.setFillColor(sf::Color::Blue);
  rect.setSize(sf::Vector2f(16,16));
  pillsEated = true;
  success = false;
}

void Pills::checkCollision(const std::vector<sf::FloatRect>&blocks)
{
  for(int i = 0; i <  blocks.size() ; i++)
    {
      if(rect.getGlobalBounds().contains(blocks[i].left,blocks[i].top))
	{
	  respawn();
	}
    }
}

sf::Vector2f Pills::spawn()
{
  int x(0);
  int y(0);
  
  if(pillsEated) {
    while(!success)
      {
	x = std::rand()% SCREEN_WIDTH;
	y = std::rand()% SCREEN_HEIGHT;
	  
	if(x%16 == 0 && y%16 ==0)
	  success = true;
      }
	
    pillsPosition.x = x;
    pillsPosition.y = y;
	
    pillsEated = !pillsEated;
  }

  rect.setPosition(pillsPosition);
  return pillsPosition;
}

void Pills::draw(sf::RenderWindow& win)
{
  win.draw(rect);
}
