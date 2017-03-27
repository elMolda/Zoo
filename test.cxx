#include <iostream>
#include "Zoo.h"

int main( int argc, char* argv[] )
{
  Zoo z;

  while( !std::cin.eof( ) )
  {
    std::string genre, name;
    std::cin >> genre >> name;
    if( genre != "" && name != "" )
      z.NewAnimal( name, genre );

  } // elihw
  std::cout << z << std::endl;

  return( 0 );
}

// eof - test.cxx
