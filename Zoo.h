#ifndef __ZOO__H__
#define __ZOO__H__

#include <ostream>
#include <list>
#include "Genre.h"

class Zoo
{
  friend std::ostream& operator<<( std::ostream& os, const Zoo& z );

public:
  Zoo( );
  virtual ~Zoo( );

  void NewAnimal( const std::string& name, const std::string& genre );
  unsigned long Count( ) const;
  void RemoveAnimal( const std::string& name );

protected:
  typedef std::list< Genre > TGenreList;

protected:
  TGenreList m_Genres;
};

#endif // __ZOO__H__

// eof - Zoo.h
