# push_swap_21school

Сортировка массива чисел.

Задача программы отсортировать заданный массив чисел за меньшее количество операций.

Доступные операции:

`sa` - `swap a` - меняет местами 2 первых числа в стеке a

`sb` - `swap b` - меняет местами 2 первых числа в стеке b

`ss` - `swap a & b` - меняет местами 2 первых числа в стеке a и b

`pa` - `push a` - первый элемент из стека b перемещается на первое место стека a 

`pb` - `push b` - первый элемент из стека a перемещается на первое место стека b

`ra` - `rotate a` - меняет местами 1 и последний элемент стека a 

`rb` - `rotate b` - меняет местами 1 и последний элемент стека b

`rr` - `rotate a & b` - меняет местами 1 и последний элемент стека a и b

`rra` - `reverse rotate a` - меняет местами последний и 1 элемент стека a

`rrb` - `reverse rotate b` - меняет местами последний и 1 элемент стека b

`rrr` - `reverse rotate a & b` - меняет местами последний и 1 элемент стека a и b


Сортировка происходит с использованием двух стеков, каждый из стеков является двусвязным списком.

Программа выводит в консоль операции, которые были выполнены при сортировке.
Для наглядности была добавлена функция, выводящая отсортированный массив чисел.

**Работа программы:**
___________________

`make` - сборка программы

`./push_swap 5 8 1 3 ...` или `./push_swap "5 8 1 3 ..."` - запуск программы

`./push_swap 5 8 1 3 ... | wc -l` - выдаст количество выполненных операций

`make fclean` - удаление скомпилированных файлов

В случае ввода повторных чисел, чисел превышающих значения int или иных символов, программа выдаст вариативную ошибку.

Ресурс для генерации чисел https://stattrek.com/statistics/random-number-generator.aspx#error




 
