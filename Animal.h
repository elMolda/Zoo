#ifndef __ANIMAL__H__
#define __ANIMAL__H__

#include <string>

class Animal
{
public:
  Animal( );
  virtual ~Animal( );

  const std::string& GetName( ) const;
  const unsigned long& GetNumberOfSpecimens( ) const;

  void SetName( const std::string& name );
  void AddOneSpecimen( );
  void EraseOneSpecimen( );

protected:
  std::string   m_Name;
  unsigned long m_Count;
};

#endif // __ANIMAL__H__

// eof - Animal.h
