texto = "100a23b"

resultado = re.sub(r'\b\d+\b', a_notacion_cientifica, texto)

print(resultado)