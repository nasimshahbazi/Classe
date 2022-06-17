#include <iostream>
#include <fstream>
#include <string>

class Stringread
{
private:
char *
   clText;
unsigned int
   clLang;
std::string
   clfilename;

public:
   Stringread();
  ~Stringread();
   Stringread(const Stringread&);

const Stringread&
   operator=(const Stringread&);
   
void
   readText(const std::string &);
void
   print();
unsigned int
   length() const;
};

Stringread :: Stringread()
{
   clText = 0;
   clLang = 0;
}

unsigned int Stringread :: length()
const
{
   return clLang;
}

Stringread :: ~Stringread()
{
   delete [] clText;
}

Stringread :: Stringread
 (
   const Stringread &b
 )
{
   delete [] clText;

   unsigned int l = b.length();

   clText = new char[l + 1];
  
   for(int i = 0; i <= l; ++i)
   {
      clText[i] = b. clText[i];
   }
}

const Stringread &Stringread :: operator=
 (
   const Stringread &b
 )
{
   delete [] clText;
  
   unsigned int l = b.length();

   clText = new char[l + 1];
  
   for(int i = 0; i <= l; ++i)
   {
      clText[i] = b.clText[i];
   }
   return *this;
}

void Stringread :: print()
{
   std::cout << "Die Dategröße ist: " << clLang << std::endl;
}

void Stringread :: readText
 (
   const std::string &filename 
 )

{
   delete[] clText;

   std::ifstream file(filename.c_str(), std::fstream::binary);

   file.seekg(0, std::fstream::beg);

   std::ifstream::pos_type begin_pos = file.tellg();

   file.seekg(0, std::fstream::end);

   clLang = file.tellg() - begin_pos;

   file.seekg(0, std::fstream::beg);


   clText = new char[clLang + 1];

   file.read(clText, clLang);

   if (file.bad())
      std::cerr << "Reading of file failed." << std::endl;

   clText[clLang] = 0;
}

int main()
{
   Stringread myString;
   myString.readText("Text.txt");
   myString.print();
}

