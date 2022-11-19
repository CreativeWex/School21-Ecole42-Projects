# pipex
Summary: This project is the discovery in detail and by programming of a UNIX mechanism

## Objectives 

Your objective is to code the Pipex program.
It should be executed in this way:

``./pipex file1 cmd1 cmd2 file2``

Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands with
their parameters.
<br>
<br>
The execution of the pipex program should do the same as the next shell command:
``< file1 cmd1 | cmd2 > file2``

## Open
Режимы

O_CREAT - если файл не существует, то он будет создан

O_WRONLY - открыть только для записи

O_TRUNC - если файл уже существует, позволяет записывать в этот файл
<br>
<br>
## Access

***int access(const char *pathname, int mode);*** проверяет, имеет ли процесс права на чтение или запись. Проверяет, существует ли файл с именем pathname. 

В случае успеха (есть все запрошенные права) возвращается нуль. При ошибке (по крайней мере один запрос прав из mode был неудовлетворен, или случилась другая ошибка), возвращается -1.

F_OK - проверяет существование файла.
<br>
<br>
## dup2

***int dup2(int oldfd, int newfd);*** делает newfd копией oldfd, закрывая newfd, если требуется
<br>
<br>
## Файловые дескрипторы

fork запускаем два процесса для двух команд в одной программе

Для работы трубе нужны дескрипторы, которые мы получим, открывая файл. Так как в linux уже предусмотрены дескрипторы 0 - stdin, 1 - stdout и 2 - stderr, то следовательно, infile - 3, outfile - 4. (end[0] - 5, end[1] - 6).

Для дочернего процесса мы хотим, чтобы infile был stdin и end[1] был stdout для того, чтобы записать результат работы cmd1 в end[1] и родительский процесс мог его прочитать.

С другой стороны, в родительском процессе мы хотим, чтобы end[0] был stdin (end[0] в этот момент ажу прочитает результат работы cmd1 из end[1]), а stdout для cmd2 будет outfile.

Для того, чтобы менять fd у stdin и stdout мы будем использовать dup2().

int execve(const char *path, char *const argv[], char *envp[]);

path - путь до команды.
argv - параметры командной строки
envp - переменная окружения (инфа о системе), нужна для execve. В данном контексте из всех параметров нас интересует только PATH, в котором хранятся все возможные пути для команд. (env в терминале). Все пути нужно разделить через split используя ':' как разделитель, execve пройдется по всем возможным путям, чтобы найти именно тот, где хранится нужная для выполнения команда.

Если искомой команды не существует, то execve ничего не будет делать и вернет -1. Иначе, выполнит команду, удалит все, связанные с ней, протекающие процессы, в том числе и переменные, так что не надо запариваться с free.

### Возможные доработки

Два дочерних процесса следует использовать для лучшей защиты. Потому что в случае только одного дочернего процесса, при запуске двух параллельных процессов (родительского и дочернего) может произойти сега в одном из процессов, ошибка о чем будет отправлена в другой процесс.

    https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901



# Код

### openfile (название файла, режим) - в зависимости от режима открывает/создает файл
    Режим 0 - infile. 
        Проверяет через access наличие файла, если файл есть (access возвращает 0) возвращаем дескриптор на открытый файл
        Если файла нет (access возвращает -1) останавливаемся
    Другой для outfile
        открывает/создает файл и выдает ему права на 777 (аналогично chmod)

### len_ch(строка, символ) - Возвращает индекс первого вхождения заданного символа
    Проходится по строке, ищет первое вхождение заданного символа, если символ отсутствует, возвращает -1.

## fullpath (команда, переменная окружения)
    char    *path; // Все пути к команде
    char    *dir;// Первый путь к команде
    char    *full;//собранная строка из команды и пути

    while (env[i] && strnstr(env[i], "PATH=", 5)) // Ищем строку PATH, в которой хранятся адресы команд
		i++;
    path = env[i] + 5; //сдвигаем на начало адресов
    while (path && char_first_encounter(path, ':') > -1) // берем только первый адрес (пока не встретится ':')
    dir = ft_str_ndup(path, char_first_encounter(path, ':')); // копируем в dir первый адрес
    full = make_command(dir, cmd); // собираем полную команду

    Если доступ есть, то возвращаем путь, если нет, то перебираем остальные адреса


## child_process (команда, переменная окружения)
Функция распознает команду, строит до нее путь и выполняет команду

    char    **args; // аргументы команды. (ls -la или grep out и тд, для команд из нескольких слов)
    char    *path; // путь до команды
    if (len_ch(args[0], '/') > -1) // Если в качестве аргумента для команды дали команду с полным путем, то path присваиваем этот путь.
    Если полного пути нет, собираем его сами в path = full_path(args[0], env);

    Выполняем команду


## parent_process (команда, переменная окружения, fd f1)

Функция создает трубу, настраивает ее концы, создает дочерний процесс, выполняет cmd 1;

    pid_t parent; // итендификатор родительского процесса
    int end[2]; // труба

    pipe(end); // Основная идея работы трубы: pipe() связывает массив интов(в данном случае end[2]) в трубу. 
    Все что происходит в end[0] видно в end[1] и наоборот + pipe назначает fd для каждого конца.

    infile является входными данными для cmd1 -> cmd 1 выполняется -> результат работы cmd 1 записывается в end[1].

    end[0] прочичитывает результат работы cmd1 из end[1] и передает его в cmd2 -> cmd2 выполняется -> результат выполнения записывается в outfile

    После заполнения концов трубы, родительский процесс end[0] будет считывать, дочерний end[1] будет записывать. Для чтения чего-то, нужно, чтобы это "чего-то" было для начала записано. cmd1 будет исполняться родителем, cmd2 ребенком.

    parent = fork(); //pipe заполняем процессами, которые появляются из fork. после форка родительский pid так и останется каким-то рандомным числом, дочерний pid станет 0, процессы выполняются параллельно.

    Цепочка if будет выполняться родительским процессом, else - дочерним.
    Родитель:
        close(end[1]); // закрываем вход для предотвращения замусоривания
        dup2(end[0], 0); // открываем выход для процесса
    Ребенок:
        close(end[0]) == -1 //закрываем вход для предотвращения замусоривания
        dup2(end[1], 1) == -1 // выход процесса перенаправляем в stdout



## main (количество параметров, параметры, переменная окружения(инфа о системе))
    f1 - fd infile
    f2 - fd outfile
    dup используется для того, чтобы поменять местами fd, связать

    f1 присваивается fd infile
    f2 присваивается fd outfile

    Операции для работы трубы:

    dup2(f1, 0); - fd infile записываем в stdin. infile станет потоком стандартого ввода.
    dup2(f2, 1); - fd outfile записываем в stdout. stdout станет потоком стандартного вывода.
    parent_process(av[2], env, f1); - передаем cmd1, env, f1.
