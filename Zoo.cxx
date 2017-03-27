#include "Zoo.h"

// -------------------------------------------------------------------------
std::ostream& operator<<( std::ostream& os, const Zoo& z )
{
  Zoo::TGenreList::const_iterator itGenre = z.m_Genres.begin( );
  for( ; itGenre != z.m_Genres.end( ); itGenre++ )
    os << *itGenre << std::endl;
  return( os );
}

// -------------------------------------------------------------------------
Zoo::
Zoo( )
{
}

// -------------------------------------------------------------------------
Zoo::
~Zoo( )
{
}

// -------------------------------------------------------------------------
void Zoo::
NewAnimal( const std::string& name, const std::string& genre )
{
  TGenreList::iterator itGenre = this->m_Genres.begin( );
  TGenreList::iterator itNewGenre = this->m_Genres.end( );
  for( ; itGenre != this->m_Genres.end( ); itGenre++ )
  {
    if( itGenre->GetName( ) == genre )
    {
      itGenre->AddOneSpecimen( name );
      itNewGenre = itGenre;

    } // fi

  } // rof

  if( itNewGenre == this->m_Genres.end( ) )
  {
    Genre gen;
    gen.SetName( genre );
    gen.AddOneSpecimen( name );
    this->m_Genres.push_back( gen );

  } // fi
}

// -------------------------------------------------------------------------
unsigned long Zoo::
Count( ) const
{
  TGenreList::const_iterator itGenre = this->m_Genres.begin( );
  unsigned long count = 0;
  for( ; itGenre != this->m_Genres.end( ); itGenre++ )
    count += itGenre->CountSpecimens( );
  return( count );
}

// -------------------------------------------------------------------------
void Zoo::
RemoveAnimal( const std::string& name )
{
  TGenreList::iterator itGenre = this->m_Genres.begin( );
  for( ; itGenre != this->m_Genres.end( ); itGenre++ )
    itGenre->EraseOneSpecimen( name );
}

// eof - Zoo.cxx
