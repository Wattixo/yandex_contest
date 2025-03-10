# backend_yandex_contest_2024
Solving tasks from training yandex contest in C++\
Решение некоторых задач из тренировочного Яндекс-Контеста
## A. Хитрый шифр
  Известная компания Тындекс в очередной раз проводит набор стажёров. Заботясь о персональных данных соискателей, компания придумала хитрый алгоритм шифрования:
- Подсчитывается количество различных символов в ФИО (регистр важен, А и а — разные символы).
- Берётся сумма цифр в дне и месяце рождения, умноженная на 64.
- Для первой (по позиции в слове) буквы фамилии определяется её номер в алфавите (в 1-индексации), умноженный на 256 (регистр буквы не важен).
- Полученные числа суммируются.
- Результат переводится в 16-чную систему счисления (в верхнем регистре).
- У результата сохраняются только 3 младших разряда (если значимых разрядов меньше, то шифр дополняется до 3-х разрядов ведущими нулями).
  
Ваша задача — помочь вычислить для каждого кандидата его шифр.

### Формат ввода
В первой строке вводится число 
N(1≤N≤10000) — количество кандидатов и шифров.
Далее следует N строк в формате CSV (fj,ij,oj,dj,mj,yj) — информация о кандидатах:
* Фамилия fj, имя ij и отчество oj(1≤∣fj∣,∣ij∣,∣oj∣≤15) — строки, состоящие из латинских букв верхнего и нижнего регистра;
* день рождения dj, месяц рождения mj и год рождения yj — целые числа, задающие корректную дату в промежутке от 1 января 1950 года до 31 декабря 2021 года.

### Формат вывода
В единственной строке выведите N строк k1, k2, …, kN, где kj — шифр j-го кандидата (в верхнем регистре). Кандидаты нумеруются с 1 до N в порядке ввода.

## B. Через тернии к клиенту
Известная компания Тындекс идёт в ногу со временем — с началом активных космических перелётов в компании открылся сервис Тындекс.Ракетакси: пользователю необходимо лишь указать координаты начала и конца перелёта, после чего за ним вылетит персональная ракета.
По сути любой заказ можно описать в виде событий четырёх типов:
1. A (accepted) - заказ принят в работу (ракета вылетела за клиентом);
2. B (boarding) - клиент сел в ракету;
3. S (success) - заказ успешно завершён (клиент вышел на планете назначения);
4. C (cancelled) - заказ отменён.

Все происходящие с ракетами события отправляются на сервера, где сразу логируются. Вот только из-за проблем со связью (метеоритные потоки, вспышки на звездах и т.д.) отправка событий иногда затягивается, из-за чего записи в получившемся логе могут идти не по порядку.

Гарантируется, что все описанные в логе события задают один из следующих сценариев:
1. A - B - S
2. A - B - C
3. A - C

Вам, как главному аналитику (и по совместительству главному программисту) ракетопарка, необходимо исследовать лог за прошедший год и определить для каждой ракеты суммарное время движения (в минутах) в течение заказов.

В каждый момент времени ракета выполняет только один заказ. Будем считать, что каждая ракета в каждый момент времени:
* или стоит на месте в ожидании заказа,
* или перемещается по космосу, выполняя заказ.

Движение начинается после принятия заказа и завершается после отмены или завершения заказа. За одну минуту не может произойти несколько событий, связанных с одной и той же ракетой.
### Формат ввода
В первой строке дано целое число N(2≤N≤200000)  — количество записей в логе. 
Следующие N строк содержат записи в логе в формате day hour minute id status:
* day(1≤d≤365)  — номер дня (сквозная нумерация с начала календарного года);
* hour(0≤h<24)  — часы;
* minute(0≤m<60)  — минуты;
* id(0≤id≤10<sup>9</sup>)  — уникальный идентификатор ракеты;
* status ∈ {A,B,S,C}  — буква, обозначающая тип события.
### Формат вывода
В единственной строке выведите через пробел суммарное время движения на заказах для каждой упомянутой в логе ракеты. Данные необходимо выводить в порядке возрастания идентификаторов ракет.

## C. Приснится же такое...
Наконец-то с царством Морфея удалось наладить дипломатические отношения! Первым делом в магазины поступили самые корректные и полные сонники, составленные в сотрудничестве с главными сномагами царства.\
Ваш близкий друг Тирания Вампадур купила такой сонник одной из первых. Но тут же её ждало разочарование. Оказалось, что некоторые сны образуют целую последовательность сюжетов, которую надо интерпретировать только целиком.\
И у Тирании оказалась именно такая ситуация. Когда-то давно ей приснилось двоичное дерево из N вершин, занумерованных целыми числами от 1 до N.
Вершина 1 являлась корнем. У каждой вершины v было до двух сыновей: левый имел номер 2⋅v, правый — 2⋅v+1 (при условии, что их номера не превосходили N). Таким образом, зная число N, дерево можно было однозначно восстановить.\
Но, к сожалению, следующие Q ночей Тирании снились похожие сны: одна из вершин дерева v менялась местами с её предком (если v была корнем дерева, то ничего не происходило). Причем эти изменения переносились между снами, всё больше и больше изменяя оригинальное дерево.\
Чтобы верно интерпретировать значение снов, Тирании нужно узнать итоговую структуру дерева после всех произошедших с ним изменений. Она просит вас помочь ей и по последовательности менявшихся вершин найти итоговую структуру дерева из её снов.\
Понимая, что в этом деле важна точность, вы расспросили Тиранию насчет процесса обмена местами вершины v с её предком.

Введем обозначения:
- p — предок вершины v, pp — предок вершины p (если таковые существуют);
- vl — левый ребенок v,
- vr — правый ребенок v;
- pl — левый ребенок p,
- pr — правый ребенок p.
  
В таком случае обмен задаётся следующими условиями:
- Изменение предка: если p — левый ребенок вершины pp, то v становится левым ребенком pp, иначе — правым.
- если v — левый ребенок вершины p, то:
1. p становится левым ребенком v;
2. vr остаётся правым ребенком v;
3. vl становится левым ребенком p;
4. pr остаётся правым ребенком p.\
![image](https://github.com/user-attachments/assets/a15f2fe4-5766-4901-bf8f-6008f2dc1b53)

- аналогично, если v — правый ребенок вершины p, то:
1. p становится правым ребенком v;
2. vl остаётся левым ребенком v;
3. vr становится правым ребенком p;
4. pl остаётся левым ребенком p.\
![image](https://github.com/user-attachments/assets/ff0c1e0b-aaaf-4e4d-8596-09073ac8d2a3)

### Формат ввода
Первая строка содержит два целых числа N и Q (1≤N≤750;1≤Q≤106) — количество вершин в дереве и количество изменений, произошедших с деревом.
В следующей строке дано Q целых чисел v1, v2, …, vq (1≤v<sub>i</sub>≤N), где v<sub>i</sub> — номер вершины, обменявшейся местами со своим предком в i-ю ночь.

### Формат вывода
В единственной строке через пробел требуется вывести номера вершин дерева после всех изменений в формате LVR, начиная с корня дерева.
Формат LVR(v) определяется рекурсивно для вершины v.
1. если у вершины v есть левый ребенок lv, то сначала выводится всё поддерево lv в формате LVR(lv);
2. выводится номер вершины v;
3. если у вершины v есть правый ребенок rv, то выводится всё поддерево rv в формате LVR(rv);


