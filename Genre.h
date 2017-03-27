#ifndef __GENRE__H__
#define __GENRE__H__

#include <ostream>
#include <list>
#include "Animal.h"

class Genre
{
  friend std::ostream& operator<<( std::ostream& os, const Genre& g );

public:
  Genre( );
  virtual ~Genre( );

  const std::string& GetName( ) const;
  void SetName( const std::string& name );

  void AddOneSpecimen( const std::string& animal );
  unsigned long CountSpecimens( ) const;
  bool EraseOneSpecimen( const std::string& animal );

protected:
  typedef std::list< Animal > TAnimalList;

protected:
  std::string m_Name;
  TAnimalList m_Animals;
};

#endif // __GENRE__H__

// eof - Genre.h
