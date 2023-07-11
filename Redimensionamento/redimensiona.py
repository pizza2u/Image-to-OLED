from PIL import Image

# Abrir a imagem
img = Image.open('spock.bmp')

# Converter a imagem para escala de cinza
img_gray = img.convert('L')

# Redimensionar a imagem para a largura e altura desejadas
width = 128  # Largura desejada
height = 64  # Altura desejada
img_resized = img_gray.resize((width, height))

# Converter a imagem em uma matriz de bytes
img_bytes = img_resized.tobytes()

# Criar uma nova imagem a partir da matriz de bytes
img_restored = Image.frombytes('L', (width, height), img_bytes)

# Salvar a imagem restaurada
img_restored.save('imagem_restaurada.bmp')
