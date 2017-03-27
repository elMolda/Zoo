#include "Genre.h"

// -------------------------------------------------------------------------
std::ostream& operator<<( std::ostream& os, const Genre& g )
{
  os << std::endl << g.GetName( );
  Genre::TAnimalList::const_iterator itAnimal = g.m_Animals.begin( );
  for( ; itAnimal != g.m_Animals.end( ); itAnimal++ )
    os
      << std::endl
      << "\t" << itAnimal->GetName( ) << " ("
      << itAnimal->GetNumberOfSpecimens( ) << ")";
  return( os );
}

// -------------------------------------------------------------------------
Genre::
Genre( )
  : m_Name( "" )
{
}

// -------------------------------------------------------------------------
Genre::
~Genre( )
{
}

// -------------------------------------------------------------------------
const std::string& Genre::
GetName( ) const
{
  return( this->m_Name );
}

// -------------------------------------------------------------------------
void Genre::
SetName( const std::string& name )
{
  this->m_Name = name;
}

// -------------------------------------------------------------------------
void Genre::
AddOneSpecimen( const std::string& animal )
{
  TAnimalList::iterator itAnimal = this->m_Animals.begin( );
  bool animalFound = false;
  for( ; itAnimal != this->m_Animals.end( ); itAnimal++ )
  {
    if( itAnimal->GetName( ) == animal )
    {
      itAnimal->AddOneSpecimen( );
      animalFound = true;

    } // fi

  } // rof

  if( !animalFound )
  {
    Animal newAnimal;
    newAnimal.SetName( animal );
    newAnimal.AddOneSpecimen( );
    this->m_Animals.push_back( newAnimal );

  } // fi
}

// -------------------------------------------------------------------------
unsigned long Genre::
CountSpecimens( ) const
{
  TAnimalList::const_iterator itAnimal = this->m_Animals.begin( );
  unsigned long count = 0;
  for( ; itAnimal != this->m_Animals.end( ); itAnimal++ )
    count += itAnimal->GetNumberOfSpecimens( );
  return( count );
}

// -------------------------------------------------------------------------
bool Genre::
EraseOneSpecimen( const std::string& animal )
{
  TAnimalList::iterator itAnimal = this->m_Animals.begin( );
  TAnimalList::iterator itToErase = this->m_Animals.end( );
  for( ; itAnimal != this->m_Animals.end( ); itAnimal++ )
  {
    if( itAnimal->GetName( ) == animal )
    {
      itAnimal->EraseOneSpecimen( );
      if( itAnimal->GetNumberOfSpecimens( )  == 0 )
        itToErase = itAnimal;

    } // fi

  } // rof

  if( itToErase != this->m_Animals.end( ) )
    this->m_Animals.erase( itToErase );
}

// eof - Genre.cxx
