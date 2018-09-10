Шпаргалка по командам гита, чтобы не забыть

git init создание репозитория
git status смотрим состояние файлов
git add . добавить все файлы в индекс
git commit -m "делаем слепок"
git push -u origin master колбасим наше чудо-юдо на гит

 y = (x >> n) & 1;    // n=0..15.  stores nth bit of x in y.  y becomes 0 or 1.
 
 x &= ~(1 << n);      // forces nth bit of x to be 0.  all other bits left alone.
 
 x &= (1<<(n+1))-1;   // leaves alone the lowest n bits of x; all higher bits set to 0.
 
 x |= (1 << n);       // forces nth bit of x to be 1.  all other bits left alone.
 
 x ^= (1 << n);       // toggles nth bit of x.  all other bits left alone.
 
 x = ~x;              // toggles ALL the bits in x.
