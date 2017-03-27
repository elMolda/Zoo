#include "Animal.h"

// -------------------------------------------------------------------------
Animal::
Animal( )
  : m_Name( "" ),
    m_Count( 0 )
{
}

// -------------------------------------------------------------------------
Animal::
~Animal( )
{
}

// -------------------------------------------------------------------------
const std::string& Animal::
GetName( ) const
{
  return( this->m_Name );
}

// -------------------------------------------------------------------------
const unsigned long& Animal::
GetNumberOfSpecimens( ) const
{
  return( this->m_Count );
}

// -------------------------------------------------------------------------
void Animal::
SetName( const std::string& name )
{
  this->m_Name = name;
}

// -------------------------------------------------------------------------
void Animal::
AddOneSpecimen( )
{
  this->m_Count++;
}

// -------------------------------------------------------------------------
void Animal::
EraseOneSpecimen( )
{
  if( this->m_Count > 0 )
    this->m_Count--;
}

// eof - Animal.cxx
