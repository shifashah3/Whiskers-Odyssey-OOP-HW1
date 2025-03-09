#include "odyssey.hpp"
#include "mover.hpp"

//g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o odyssey.exe
//.\odyssey.exe

int treatsLeft = 40, nCollarsFound = 0;
string gameState  = "Running";

enum Location {temporal_tower, portal_arch, pet_haven, cozy_cottage, catnip_fields, paws_peak, talking_meadows, hills_of_oop, whiskering_woods, bewildering};
Location current_location=pet_haven;
int portal_Arch=0;
int collars_from_hill=1;
int collars_from_woods=1;
int collars_from_paws=1;



// This is a demo implementation of makeMove function
// It doesn't follow the game rules at all
// You have to implement it according to game logic 
void makeMove(string direction)
{
	while (gameState!="Lost" || gameState!="Won" || treatsLeft!=0)
	{
		if (direction == "East") //When Right Arrow is pressed
		{ // only portal_arch, pet haven and whiskering woods can move right

			switch(current_location)
			{
				case portal_arch: // portal arch --> pet haven
				{
					if (treatsLeft>=1){
					current_location=pet_haven;
					treatsLeft-=1;
					moveEast();
					break; }
					else;{
						gameState="Lost";
					}
					break;
				}
				case pet_haven: // pet haven --> cozy cottage
				{	
					if (treatsLeft>=1){
					current_location= cozy_cottage;
					treatsLeft-=1;
					moveEast();
					break; }
					else;{
						gameState="Lost";
					}
					break;
				}
				case whiskering_woods: // whiskering woods --> hills of oop
				{
					if (treatsLeft>=4)
					{
					current_location=hills_of_oop;
					treatsLeft-=4;
					if (collars_from_hill==1)
					{
						nCollarsFound++;
						collars_from_hill-=1;
					}
					
					moveEast(); 
					break;
					}
					else;{
						gameState="Lost";
					}
					break;
				}

				default:
				{
					treatsLeft-=1;
					break;
				}
			}
			// Call this function only if alex needs to be moved
		break;	
		}

		else if (direction == "West") //When Left Arrow is pressed
		{
			// only cozy cottage, pet haven, portal arch and hills of oop can move left
			switch(current_location)
			{
				case 1:  // portal arch --> temporal tower
					switch (nCollarsFound)
					{
						case 3:
						
							current_location=temporal_tower;
							if (treatsLeft<5)
							{
								gameState="Lost";
								break;
							}
							else
							{
								moveWest();
								gameState = "Won";
								treatsLeft-=5;
								break;
							}
							
						
						default:
							treatsLeft-=1;
							break;
						
						
					}
					break;
				
				
				case 2:  // pet haven to portal arch
					current_location=portal_arch;
					
					if (portal_Arch >=2)
					{
						gameState = "Lost";
						moveWest();
						break;
					}
					else;
					{	
						if (treatsLeft>=2){
						treatsLeft-=2;
						portal_Arch+=1;
						moveWest();
						break;  }
						else;{
							gameState="Lost";
						}
						break;
					}

					break;
				case 3:  // cozy cottage to pet haven
					if (treatsLeft>=1){
					current_location=pet_haven;
					treatsLeft--;
					moveWest();  
					break;}
					else;{
						gameState="Lost";
					}
					break;

				case 7: // hills of oop --> whiskering woods
					if (treatsLeft>=2)
					{
						current_location=whiskering_woods;
						treatsLeft-=2;
						if (collars_from_woods==1)
						{
							nCollarsFound++;
							collars_from_woods-=1;
						}
						moveWest();
						break;
					}
					else;
					{
						gameState="Lost";
					}
					break;

				default:
					treatsLeft--;
					break;
			
			}
			break;
		}



		else if (direction == "North") //When Up Arrow is pressed
		{ // only whiskering woods, hills of oop, talking meadows, paws peaks and cozy cottage
		switch (current_location)
		{

			case 3: // cozy xottage --> catnip fields
			{
				if (treatsLeft>=2){
				current_location=catnip_fields;
				treatsLeft-=2;
				moveNorth();
				break;}
				else;{
					gameState="Lost";
				}
				break;
			}

			case 5:  // paws peaks --> cozy cottage
			{
				if (treatsLeft>=1){
				current_location=cozy_cottage;
				treatsLeft-=1;
				moveNorth();
				break;}
				else;{
					gameState="Lost";
				}
				break;
			}

			case 6: // talking meadows --> pet haven
			{
				if (treatsLeft>=1){
				current_location=pet_haven;
				treatsLeft-=1;
				moveNorth();
				break;
				}
				else;{
					gameState="Lost";
				}
				break;
			}

			case 7: // hills of oop --> talking meadows
			{
				if (treatsLeft>=3)
				{
				current_location=talking_meadows;
				treatsLeft-=3;
				moveNorth();
				break;
				}
				else;
				{
					gameState="Lost";
				}
				break;
			}

			case 8: // whiskering woods --> bewildering bog
			{
				switch(treatsLeft<3)
					{

						case 0:
						moveNorth();
						current_location=bewildering;
						treatsLeft-=3;
						gameState="Lost";
						break;

						default:
						treatsLeft--;
						break;
					}

					break;
				
			
			}

			default:
			{
				treatsLeft--;
				break;
			}

		}
			// cout<<"Provide North move implementation"<<endl;
			  	// Call this function only if alex needs to be moved
			// gameState = "Won";	// Set this gameState when the game is Won
		break;
		}

		else if (direction == "South") //When Down Arrow is pressed
		{ // only portal arch, pet haven, talking meadows, cozy cottage and catnip fields
		
			switch (current_location)
			{
				case 1: // portal arch --> bewildering bag
				{
					switch(treatsLeft<3)
					{

						case 0:
						moveSouth();
						current_location=bewildering;
						treatsLeft-=3;
						gameState="Lost";
						break;

						default:
						treatsLeft--;
						break;
					}

					break;
					

				}

				case 2: // pet haven --> talking meadows
				{
					if (treatsLeft>=3){
					current_location=talking_meadows;
					treatsLeft-=3;
					moveSouth(); 
					break;}
					else;{
						gameState="Lost";
					}
					break;
				}

				case 3: // cozy cottage --> paws peaks
				{
					if (treatsLeft>=2){
					current_location=paws_peak;
					treatsLeft-=2;
					if (collars_from_paws==1)
					{
						nCollarsFound++;
						collars_from_paws-=1;
					}
					moveSouth(); 
					break;}
					else;{
						gameState="Lost";
					}

					break;
				}

				case 4: // catnip fields --> cozy cottage
				{
					if (treatsLeft>=1){
					current_location=cozy_cottage;
					treatsLeft-=1;
					moveSouth(); 
					break;}
					else;{
						gameState="Lost";
					}
					break;
				}

				case 6: // talking meadows --> hills of oop
				{
					if (treatsLeft>=4){
					current_location=hills_of_oop;
					treatsLeft-=4;
					if (collars_from_hill==1)
					{
						nCollarsFound++;
						collars_from_hill-=1;
					}
						
					moveSouth(); 
					break;}

					else;{
						gameState="Lost";
					}
					break;
				}
				default:
				{
					treatsLeft-=1;
				}
			}

		break;

		}

	}
	if (treatsLeft==0)
	{
		gameState="Lost";
	}
	

}


			// cout<<"Provide South move implementation"<<endl;
			 // Call this function only if alex needs to be moved
			// gameState = "Running";