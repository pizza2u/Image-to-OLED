# Exibindo imagem em OLED 0,96''
<p align="center">
 <img src= "https://github.com/pizza2u/Image-to-oled/blob/main/Output/b.jpeg" width="500" height="300">
</p>

Por se tratar de um display OLED 0,96'', as dimensões ideiais é 128x64, dessa forma a imagem precisa ser redimensionada. Apesar disso, é necessário converter a imagem RGB para Bitmap, pois esses displays OLED trabalham com pixels individuais e cada pixel precisa ser controlado individualmente para ser exibido.

>> Bitmap é um formato de imagem que representa graficamente uma imagem por meio de uma matriz de pixels. Cada pixel é um ponto individual na imagem e possui informações sobre sua cor ou tonalidade. O termo "bitmap" vem da combinação das palavras em inglês "bit" (unidade fundamental de informação) e "map" (mapeamento), indicando que a imagem é mapeada através de bits.
- Ao converter uma imagem para o formato bitmap, é feito o mapeamento de cada pixel da imagem original para um valor correspondente no bitmap. Isso envolve a definição de quais pixels devem ser ligados ou desligados com base nas cores da imagem original.
- A matriz de pixels de um bitmap possui uma correspondência direta com a resolução da imagem, ou seja, o número de pixels ao longo de suas dimensões horizontal e vertical. Quanto maior a resolução, maior será a quantidade de pixels e, consequentemente, maior a quantidade de informações necessárias para representar a imagem.
- A conversão para bitmap é necessária porque os displays OLED geralmente não têm capacidade de processar diretamente formatos de imagem complexos, como JPEG ou PNG. Ao converter a imagem para bitmap, você simplifica os dados da imagem para um formato que o display pode interpretar e exibir corretamente.
