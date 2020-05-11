# Algorytmy z powracaniem

W plikach `fleury.h`, `hierholzer.h` i `hamilton.c` znajdują się linie `TODO` do uzupełnienia

# Krótkie omówienie kodu

## `stack.h`

Implementacja stosu, czyli kolejki LIFO (Last-In-First-Out)

```c
// tworzenie stosu
struct stack *stack_create(int size);

// niszczenie stosu
void stack_destroy(struct stack *s);

// umieszczenie wartości na szczycie stosu
void stack_push(struct stack *s, int value);

// pobranie wartości ze szczytu stosu
int stack_pop(struct stack *s);

// podejrzenie wartości na szczycie stosu (bez jej pobierania)
int stack_peek(struct stack *s);

// sprawdzenie czy stos jest pusty
bool stack_is_empty(struct stack *s);
```

## `adjacency_matrix.h`

Reprezentacja grafu w postaci macierzy sąsiedztwa. __Uwaga!__ Proszę zwrócić uwagę na pewne różnice względem poprzedniego zadania

```c
// tworzenie grafu o zadanej liczbie wierzchołków
struct graph *graph_create(int size);

// tworzenie kopii grafu
struct graph *graph_copy(struct graph *g);

// niszczenie grafu
void graph_destroy(struct graph *g);

// sprawdzanie czy istnieje krawędź
bool graph_has_edge(struct graph *g, int i, int j);

// dodawanie krawędzi ze zliczaniem
void graph_add_edge(struct graph *g, int i,int j);

// usuwanie krawędzi ze zliczaniem
void graph_remove_edge(struct graph *g, int i, int j);

// DFS
void dfs(struct graph *g, int i, int *visited);
```

## `instance_generator.h`

Generator instancji (szerzej opisany na stronie domowej)

## `euler.c`, `fleury.h` i `hierholzer.h`

- `euler.c` tworzy grafy o stałej liczbie wierzchołków i zmiennej gęstości (czyli liczbie krawędzi)
- Dla każdego grafu wywoływana jest funkcja `euler`, która znajduje cykl Eulera
- Znaleziony cykl jest sprawdzany (użyta musi być każda krawędź dokładnie raz)
- Pliki nagłówkowe `fleury.h` i `hierholzer.h` zawierają implementację funkcji `euler`
- Kompilacja z flagą `-DFLEURY` włącza implementację z pliku `fleury.h`
- Kompilacja z flagą `-DHIERHOLZER` włączą implementację z pliku `hierholzer.h`

## `hamilton.c`

- `hamilton.c` tworzy grafy o zmiennej liczbie wierzchołków i stałej gęstości 0.5
- Dla każdego grafu początek poszukiwania cyklu Hamiltona ustawiany jest na wierzchołek o najniższym stopniu dodatnim
- Jeżeli funkcja `hamilton` znajdzie cykl, to jest on sprawdzany (czy kolejne wierzchołki są połączone, czy utworzono cykl i czy wierzchołki się nie powtarzają)
- Domyślny generator instancji tworzy graf z cyklem Hamiltona, więc funkcja `hamilton` musi go znaleźć
- Kompilacja z flagą `-DHAMILTON_NO_CYCLE` ma dwa efekty:
  - Zmienia się tablica z wielkościami grafów do generowania (pełny przegląd grafu by stwierdzić brak cyklu Hamiltona jest bardzo długotrwały)
  - Aby wymusić brak cyklu Hamiltona, usuwana jest minimalna liczba krawędzi powodująca, że pewien wierzchołek jest izolowany (nie ma żadnych krawędzi)

## `Makefile`

Zawiera reguły do zbudowania czterech plików wykonywalnych:
- `euler-fleury`
- `euler-hierholzer`
- `hamilton`
- `hamilton-no-cycle`

# Zadania

- [2 pkt] Zaimplementuj funkcję `euler` w pliku `fleury.h`
- [2 pkt] Zaimplementuj funkcję `euler` w pliku `hierholzer.h`
- [2 pkt] Zaimplementuj funkcję `hamilton` w pliku `hamilton.c`
