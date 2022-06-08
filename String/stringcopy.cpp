#include <iostream> // Ein Text als string Kopieren.

class String
{
//membervariable in diese KLasse ist clText
private:

char *
   clText; //

public:
   String();
  ~String();

void 
   copy(char *);
void
   copy(String &);//Texte 
void 
   print();
unsigned int 
   length();//Methoden, konnen für jede Instanze diese Klasse aufgerufen werden.
};
 
String :: String()
{
   clText = 0;
}

String :: ~String()
{
  delete [] clText;
}

unsigned int lengthfunc //eine Funktion. eine Funktion hat keine membervariable. 
 (
   char *satz
 )
{
   if(satz == NULL)
      return 0;

   int i = 0;
   while (satz[i] != 0)
   {
      ++i;
   }

   return i;
}

unsigned int String :: length()//eine Methode für die Klasse String
{
   return lengthfunc(clText); // Ich rufe Function length für die membervariable auf , function aufrufen ist bei functionname();
}

void String :: print()
{
   std::cout << "String ist: " << clText << std::endl;
}

void String :: copy
 (
   char *variable
 )
{
   delete [] clText;

   unsigned int l = lengthfunc(variable);

   clText = new char[l + 1];

   for(int i = 0; i <= l; ++i)
   {
      clText[i] = variable[i];
   }

   //std::cout << variable << std ::endl;
}

void String :: copy
 (
   String word //Eine Instanz der Klasse String. hier programmierte Klasse.
 )
{
   delete [] clText;

   unsigned int l = word.length();//Methode length() für eine Instance die Klasse String.  

   clText = new char[l + 1];

   for(int i = 0; i <= l; ++i)
   {
      clText[i] = word.clText[i];//membervariable von word wird copiered auf die locale membervariable.
   }
   //std::cout << variable2 << std::endl;
}

int main()
{
   String myString;
   myString.copy("Hallo");//hier will ich ein character pointer kopieren.
   std::cout << "Die Länge ist: " << myString.length() << std::endl;
   myString.print();


   String myString2;

   myString2.copy(myString);//hier will ich ein String kopieren.ich rufe objecte mystring22
45
   myString2.print();
}

