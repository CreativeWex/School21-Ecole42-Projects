#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
    std::cout << _name << ": Memory has been cleaned\n";
}

void Zombie::announce() const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string nameValue)
{
    _name = nameValue;
}

 
//  - Куча медленнее стека выделяет и освобождает ресурсы, автоматически не очищается 
// подвержена фрагментации.

// +Время жизни переменной не ограничено процессом выполнения. Без явного вызова
//  delete переменная будет существовать до конца выполнения программы.

// + стек можно переполнить объектами с существенными размерами

// + Зная адрес переменной в куче, к ней можно получить доступ из любой области видимости.

//     В итоге, создание в стеке следует использовать в случаях, когда переменная небольшого или приемлемого размера либо используется только здесь и нигде больше.
// Если же переменная должна использоваться в процессе жизни всей программы, доступ к ней нужен в любой момент времени,
// ее создание/копирование занимает много времени/памяти или же неизвестно заранее, какой объем памяти нужен, то есть смысл использовать кучу
// (создать один раз и потом использовать готовый экземпляр из кучи, нежели создавать и инициализировать каждый раз аналог в стеке).
// Однако, при работе с кучей нужно быть осторожным. Ошибки при работе с динамической памятью чреваты утечками памяти и sigsegv-ами.