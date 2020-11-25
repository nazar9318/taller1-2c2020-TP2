# Correcciones

Cuidado con las APIs que tienen métodos threadsafe y otros que no, documentar cuales métodos son threadsafe (o sea, los que usan mutex), o meterle mutex a todos.
Tratar de mantener los includes en los headers lo más chicos posibles, usar forward declarations cuando sea posible

Nota: 10
