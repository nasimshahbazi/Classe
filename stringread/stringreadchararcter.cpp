class Stringread
{
private:
char *
   clText;
unsigned int 
   clLang;

public:
   Stringread();
  ~Stringread();
   Stringread(const Stringread &b);

const Stringread&
   operator=(const Stringread&);

void
   readTxt(const std::string &filename);//muss ein variablen name sein, &wegen kein kopi brache ich
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

unsigned int Stringread :: length()
   const
{
   return clLang;
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

void Stringread ::print()
{
   std::cout << "Die Dateigröße ist: " << clLang << std::endl;

   if (clText)//weil Pointer muss nicht auf null zeigen
      std::cout << clText << std::endl;
}

void Stringread :: readTxt
 (
   const std::string &filename
 )
{
   std::ofstream out;

   out.open("ausgabe.txt", std::ofstream::app);
   
   if(!out.good())
   {
      std::cout << "Die Datei konnte nicht zum schreiben geöffnet werden. " << std::endl;
   }
   
   std::ifstream in;
   in.open(filename.c_str(), std::fstream::binary);//from filename i want to have charachter pointer char *, liese die binar ein. 

   if(!in.good())
   {
      std::cout << "Die Datei konnte nicht zum lesen geöffnet werden. " << std::endl;
   }
   else
   //if(in.good())
   {
      in.seekg(0, std::fstream::beg);
 
      std::ifstream::pos_type begin_pos = in.tellg();
 
      in.seekg(0, std::fstream::end);
 
      clLang = in.tellg() - begin_pos;
 
      in.seekg(0, std::fstream::beg);

      delete [] clText;
      clText = new char[clLang + 1];

      char mychar;
      int zahl = 0;
 
      while(!in.eof())
      {
         in.get(mychar);//ich muss auch speicheplaz resevieren.ibrache ich die lange, //schreibe ich zweite filename
         if(!in.eof())
         {
            clText[zahl] = mychar;

            out << mychar;//speiche platz resevieren, clText[0] =erste,brache ich eine schleife , ++i)clText[i] = mycharac
            ++zahl;
         }
      }
      clText[zahl] = 0;
   }
}

int main()
{
   Stringread myString;
   myString.print();

   myString.readTxt("Text.txt");
   myString.print();

   Stringread myString2;
   myString2 = myString;
   myString.print();
}
