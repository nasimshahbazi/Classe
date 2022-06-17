#include <iostream>
#include <fstream>
#include <string>

class Stringread
{
private:
char* 
   clText;

unsigned int
   clLang;

std::string
   clfilename;

unsigned int
   clRow;

public:
   Stringread();
  ~Stringread();
   Stringread(const Stringread&);

const Stringread&
   operator=(const Stringread&);
 
void 
   readText(const std::string &);
  
unsigned int
   countRow();

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

Stringread :: ~Stringread()
{
   delete [] clText;
}

Stringread :: Stringread
 (
   const Stringread &b
 )
{
   delete[] clText;

   unsigned int l = b. length();

   clText = new char[l + 1];

   for (int i = 0; i <= l; ++i)
   {
      clText[i] = b. clText[i];
   }
}

const Stringread &Stringread :: operator=
 (
   const Stringread&b
 )
{
   delete [] clText;
   
   unsigned int l = b. length();

   clText = new char [l + 1];

   for (int i = 0; i <=l; ++i)
   { 
      clText[i] = b.clText[i];
   }  
   return *this;
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

void Stringread :: print()
{
   std::cout << "Die Dateigröße ist: " << clLang << std::endl;
   std::cout << "Die Anzahl die Zeilen sind: " << countRow() << std::endl;
}

unsigned int Stringread :: length()
const
{
   return clLang;
}

unsigned int Stringread :: countRow()
{
   clRow = 1;
  
   for (int i=0; i < clLang - 1; ++i)
   {
      if(clText[i] == '\n')
      { 
         ++clRow;
      }
   }
   return clRow;
}

int main()
{
   Stringread myString;
   myString.readText("Text.txt");
   myString.print();
}
