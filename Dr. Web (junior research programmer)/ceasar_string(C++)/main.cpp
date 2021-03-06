#include <ostream>
#include <iostream>


std::wstring get_ceasar_string(std::wstring& str) // use reference to prevent extra copying
{
  const wchar_t shift = 3;
  std::wstring res;
  
  res.reserve(str.size()); //Better to allocate memory once instead of 
                           //if (str.size() == str.capacity()) /allocate 2*capacity mem/
  
  //using "range-based for" to use operator[] less
  for (auto const &symbol : str) 
  {
    if (symbol >= L'a' && symbol <= L'z') 
    {
      res += L'a' + (symbol - L'a' + shift) % (L'z' - L'a' + 1);
      continue;
    }

    if (symbol >= L'A' && symbol <= L'Z') 
    {
      res += L'A' + (symbol - L'A' + shift) % (L'z' - L'a' + 1);
      continue;
    }

    res += symbol;
  }

  return std::move(res); //std::move() to use constr(wstring&&)
                         //and not copy twice
}

int main() 
{
  std::wstring str = L"Somebody once told me the world is gonna roll me!";
  std::wstring str_crypted = get_ceasar_string(str);

  std::wcout << str_crypted << std::endl;

  return 0;
}