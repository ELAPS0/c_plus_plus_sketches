# Любопытные особенности порограммирования на языке С++ (и немного pure C)

Здесь рассмотрены те случаи из практики, для разбора которых пришлось расширить кругозор.
## deleter.cpp
Иллюстрация использования deleter'а в shared_ptr и unique_prt.
Деструктор базового класса не имеет модификатор virtual, но тем не менее при использовании shared_ptr <Base>, ссылающегося на объект класс Derived, освобждение памяти происходит корректно, чего не скажешь о unique_ptr.
## Return value optimisation
Не часто вспоминаемая тема, которая может упростить жизнь нечастному прораммисту в борьбе за производительность. 
Предельно простой случай - функция возвращает объект по значению. Сам объект создается внутри функции, как локальная переменная. Казалось бы, что вызов конструктора копирования (порутчик, про С++ 11 пока ни слова!) неизбежен. А не тут то было. Приведенный пример показывает, что это не так. Компилятор самостоятельно избавил нас от лишних накладных расходов, создав возвращаемый объект заранее и использовав его при заполеннии в функции foo. Если быть точным, то данный пример это уже не просто RVO, а NRVO, более сложная оптимизация. Подробности здесь http://alenacpp.blogspot.com/2008/02/rvo-nrvo.html

Ну а теперь можно и про 11й стандарт. Если помешать компилятору использовать оптимизацию NRVO, то он потарается задействовать оператор перемещения, если таковой найдется у передаваемого объекта. На мой взгляд неожиданная, но безопасная оптимизация о которой стоит помнить, в первую очередь, при работе с объетами STL. 

## ctor.c
Конструкторы и деструкторы есть не только в C++ $-). Функция __libc_start_main из библиотеки glibc, помимо прочей подготовительной работы, организует запуск всех функций, имеющих атрибут constructor до вызова функции main, а имеющих атрибут destructor - после.
  
