s = "programacion"

# Índices negativos cuentan desde el final (-1 es el último carácter)
print(s[0])       # 'p' (primer carácter)
print(s[-1])      # 'n' (último carácter)

# Subcadena desde el índice 0 hasta antes del 7
print(s[0:7])     # 'programa'

# Reversión de cadena
print(s[::-1])    # 'noicamargorp'

# Tomar caracteres en posiciones pares
print(s[::2])     # 'pormco'

linea = "100 200  300\n"

# Separa por espacios automáticamente ignorando múltiples espacios consecutivos
numeros = linea.split() 
print(numeros)  # ['100', '200', '300'] (Son cadenas de texto)

# Lectura rápida de variables en competencias:
#a, b, c = map(int, input().split())  # Lee "100 200 300" y lo convierte a enteros
a, b, c = map(int, linea.split())  # Convierte la lista de cadenas a enteros
print(a, b, c)  # 100 200 300

palabras = ["icpc", "gran", "premio"]

# Une los elementos con un espacio entre ellos
resultado = " ".join(palabras)
print(resultado)  # "icpc gran premio"

# Une sin separadores
print("".join(palabras))  # "icpcgranpremio"

# Ejemplo para un problema de censura o reemplazo
s = "el mesero trajo la cuenta, gracias mesero"
s_limpia = s.replace("mesero", "taquero")

print(s_limpia)  # "el taquero trajo la cuenta, gracias taquero"

cadena = "   hola mundo\n"
print(cadena.strip())  # "hola mundo"

import re

texto = "El codigo es RA180000 en el año 20000"

# 1. re.findall: Encuentra TODAS las coincidencias del patrón y las regresa en una lista
numeros = re.findall(r'\d+', texto)
print(numeros)  # ['180000', '20000']

# 2. re.sub(patrón, reemplazo, texto): Reemplaza texto basado en el patrón
# Reemplazar ceros continuos al final de un número por notación científica
resultado = re.sub(r'1000000000', r'10^{9}', texto)

# 3. re.match o re.search: Verifica si el texto cumple un patrón
if re.search(r'RA\d+', texto):
    print("Contiene un ID válido")

import re

def a_notacion_cientifica(match):
    # match.group(0) contiene el texto del número encontrado
    num_str = match.group(0)
    
    # Si es un número pequeño (ej. de 1 a 3 dígitos), lo dejamos igual
    if len(num_str) < 4:
        return num_str
    
    # Calculamos el exponente (longitud total del número menos 1)
    exponente = len(num_str) - 1
    
    # La mantisa toma el primer dígito y los decimales sin ceros a la derecha
    primer_digito = num_str[0]
    resto = num_str[1:].rstrip('0')
    
    if resto:
        mantisa = f"{primer_digito}.{resto}"
    else:
        mantisa = primer_digito
        
    # Retornamos el formato en LaTeX: 1.234 \cdot 10^{8}
    return f"{mantisa} \\cdot 10^{{{exponente}}}"

# Texto de prueba
texto = "Tenemos valores de 1000000000 y 123400000 pero el id es 42 y 20000"

# El patrón \b\d+\b busca cualquier número entero completo
resultado = re.sub(r'\b\d+\b', a_notacion_cientifica, texto)

print(resultado)