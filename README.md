# ft_containers
Реализация std::vector, std::map, std::stack C++98

- Actual Status : Не законченый проект

## Road to finish

- 18.11 - Реализация конструкторов в ft::vector, настройка итераторов
- 19.11 - Переделал traits_alloc на alloc тк в traits с C++11, реализация конструкторов
- 22.11 - реализовал конструкторы
        - operator==, ft: clear (not std), max_size, resize, capacity, empty
        - не доделаны ft push_back
- 23.11 - Изменил структуру папок + Makefile, добавил std_main для тестов на время работы.
        - исправил max_size, 
- 26.11 - Добавил функцию assign, но не уверен правильно ли прототипирую её
        - исправил empty(), добавил pop_back()
- 27.11 - добавил erase()
- 29.11 - добавил insert()
        
* надо исправить конструктор и вместо helper вызывать assign

## Используемые технологии:
- std::allocator
- std::iterator