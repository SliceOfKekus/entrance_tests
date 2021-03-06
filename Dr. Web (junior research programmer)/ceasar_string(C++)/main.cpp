#include <ostream>
#include <iostream>


std::wstring get_ceasar_string(std::wstring& str) //std::wstring&& func_name(std::wstring& str)
{                                                //Возвращаем r-value, чтобы не копировать лишний раз
  const wchar_t shift = 3;
  std::wstring res;

  res.reserve(str.size()); //Уменьшаем кол-во 
  //using range-based for
  //for (auto symbol : str) ??? Снижает кол-во использования оператора []
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

  return std::move(res); //std::move() ???
}

int main() 
{
  std::wstring str = L"Somebody once told me the world is gonna roll me!";
  std::wstring str_crypted = get_ceasar_string(str); //use constructor with && instead of cons with & ???

  std::wcout << str_crypted << std::endl;

  return 0;
}