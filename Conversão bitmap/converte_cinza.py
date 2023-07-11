from PIL import Image
import numpy as np

img = Image.open('spock.jpg') # Abre a imagem
ary = np.array(img) # Converte a imagem numa matriz Numpy

#O programa pega uma imagem rgb e a converte em uma matriz numpy. Em seguida, divide-o em 3 vetores, um para cada canal. Eu uso os vetores de cor para criar um vetor cinza. Depois disso, ele compara os elementos com 128, se menor que escreve 0 (preto),
#  caso contrário, é 255. O próximo passo é remodelar e salvar.
r,g,b = np.split(ary,3,axis=2)
r=r.reshape(-1)
g=r.reshape(-1)
b=r.reshape(-1)

bitmap = list(map(lambda x: 0.299*x[0]+0.587*x[1]+0.114*x[2], # Cálculo dos valores de escala de cinza
zip(r,g,b)))
# Essas linhas aplicam uma função lambda a cada elemento dos vetores de cor (R, G, B) para calcular os valores dos 
# pixels em escala de cinza. A função lambda multiplica cada valor de canal (R, G, B) pelo respectivo fator de ponderação (0.299, 0.587, 0.114) 
# e, em seguida, soma os resultados.
bitmap = np.array(bitmap).reshape([ary.shape[0], ary.shape[1]]) #Remodelação da matriz 
bitmap = np.dot((bitmap > 128).astype(float),255) #Binarização dos valores
im = Image.fromarray(bitmap.astype(np.uint8)) # Criação da imagem em escala cinza
im.save('spock.bmp') # Armazenamento