#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <jpeglib.h>
#include <stdbool.h> 
#include "unistd.h"
 
/**
 * @brief Contains color data for a single pixel.
 * @param (uint8_t) pixel`s  amountOfRed
 * @param (uint8_t) pixel`s  amountOfGreen
 * @param (uint8_t) pixel`s  amountOfBlue
 */
struct pixel_rgb_t {

    /**
     * Pixel, help to build images 
     * in computer graphics. 
     * 
     * One can describe Pixel just as a simple "Color-Point", 
     * that consists some specific ammount of 
     * the basic colors red, green, blue
     * 
     * We store the ammount, of the colors in uint8_t, 
     * to ensure, the pixel_rgb_t will just claim 
     * the needed 24 Bit. 
    */

    uint8_t amountOfRed; 
    uint8_t amountOfGreen; 
    uint8_t amountOfBlue; 
};

/**
 * @brief Defines an image size.
 */
struct image_size_t {
    unsigned int width;
    unsigned int height;
};
 


typedef struct pixel_rgb_t pixel_rgb_t;
typedef struct image_size_t image_size_t;
 

/**
 * @brief function that recalculate the values of the certain color channel
 * @param (uint8_t) colorChannel_P_00
 * @param (uint8_t) colorChannel_P_10
 * @param (uint8_t) colorChannel_P_01
 * @param (uint8_t) colorChannel_P_11
 * 
 * @param (float) dX , "x-differece" to the expecting output value 
 * @param (float) dY , "y-differece" to the expecting output value  
*/

uint8_t calculate_channel(uint8_t colorChannel_P_00, uint8_t colorChannel_P_10,  
                            uint8_t colorChannel_P_01,  uint8_t colorChannel_P_11, float dX, float dY){
 
    // 𝑸𝟎 =(𝟏−𝒅𝒙)∗𝑷𝟎𝟎 +𝒅𝒙 ∗ 𝑷𝟏𝟎

    uint8_t Q_0 = (1 - dX) * colorChannel_P_00 + dX * colorChannel_P_10;

    // 𝑸𝟏 =(𝟏−𝒅𝒙)∗𝑷𝟎𝟏 +𝒅𝒙 ∗ 𝑷𝟏𝟏

    uint8_t Q_1 = (1 - dX) * colorChannel_P_01 + dX * colorChannel_P_11;

    // 𝑷(𝒙,𝒚)=(𝟏−𝒅𝒚)∗𝑸𝟎 +𝒅𝒚 ∗ 𝑸𝟏

    uint8_t P_x_y = (1 - dY) *  Q_0 + dY * Q_1;

    return P_x_y;
}


/**
 * @brief Scales an image by applying a billinear interpolation filter.
 *
 * @param in pixel data of input image
 * @param out  pixel data of output image. Has to be pre allocated.
 * @param src_sz the size of the input image
 * @param trgt_sz the desired output size.
 */

void resize_image(pixel_rgb_t *in, pixel_rgb_t *out, image_size_t src_sz, image_size_t trgt_sz) {

    // pointer to the output image 
    pixel_rgb_t *pd = out;


    // pointer to the input image 
    pixel_rgb_t *ps = in;

    // we calculate the scaling dimensions 

    const float x_scaling =  ((float) (src_sz.width )) / trgt_sz.width;  

    const float y_scaling =  ((float) (src_sz.height )) / trgt_sz.height; 
   
    size_t ctr = 0; 

    // we will iterate through the demanded sizes , of the output file 

    for(unsigned int height=0 ; height < trgt_sz.height ; height++)
    {
        for(unsigned int width=0; width<trgt_sz.width; width++)
        {

            // we try to figure out the position, of a P(x,y) from the output file 

            // at first we calculate x,y of a certain Point P(x,y) from the out_put_file

            const float out_put_p_x =  (x_scaling * width); 
            
            const float  out_put_p_y =  (y_scaling * height);

            // we can get the "out_put_p_y" associated point, from the source file, if we 
            // cast the values above to int 

            const int associated_p_x = (int)  out_put_p_x; 
            
            const int associated_p_y = (int)  out_put_p_y;


            // now we calculate the differences, between the "calculated" out_put_p and the associated ones 

            const float dX =  out_put_p_x - associated_p_x ; 

            const float dY =  out_put_p_y - associated_p_y ; 


            // the image was read as some appneded jpeg-scanline, so 
            // we need a way to recalculate the needed points, from their position in a large array

            // because the scanlines are appnded next to each other, 
            // we will simply use "associated_p_y  * src_sz.width" to calculate the expected scanline 
            // and use associated_p_x  as some offset to get the needed pixel 

            // At first we will calculate the current pointer to that array 


            const int current_src_pixel_ptr =  associated_p_y  * src_sz.width + associated_p_x ;

            // P_00, is the one, where the ptr is pointing to 

            pixel_rgb_t P_00 = ps[current_src_pixel_ptr];

            // P_01, is the one, 1 x dimension next to  P_00 

            pixel_rgb_t P_10 = ps[current_src_pixel_ptr + 1];

            // P_10, is the one, 1 y dimension next to  P_00 

            pixel_rgb_t P_01 = ps[current_src_pixel_ptr + src_sz.width];

            // P_11, is the one, 1 y dimension and 1 x dimesnion next to  P_00 

            pixel_rgb_t P_11 = ps[current_src_pixel_ptr + src_sz.width + 1];
 
            pd[ctr].amountOfRed =  calculate_channel(P_00.amountOfRed, P_10.amountOfRed,  
                            P_01.amountOfRed,  P_11.amountOfRed,   dX,  dY);
            

            pd[ctr].amountOfGreen =  calculate_channel(P_00.amountOfGreen, P_10.amountOfGreen,  
                            P_01.amountOfGreen,  P_11.amountOfGreen,   dX,  dY);

            pd[ctr].amountOfBlue =  calculate_channel(P_00.amountOfBlue, P_10.amountOfBlue,  
                            P_01.amountOfBlue,  P_11.amountOfBlue,   dX,  dY);


            ctr++;
        } 
    }
}


/**
 * @brief Loads pixels from a JPEG file into memory.
 * @param name the path of the file to read
 * @param img pointer to pixel data. Will be allocated.
 * @param size the size of the image. Will be set by this function
 */
void load_jpeg(const char *name, pixel_rgb_t **img, image_size_t *const size) {
    uint8_t r, g, b;
    int width, height;
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile;
    JSAMPARRAY pJpegBuffer;
    int row_stride; 
    if ((infile = fopen(name, "rb")) == NULL) {
        fprintf(stderr, "can't open %s\n", name);
        exit(1);
    }
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    (void) jpeg_read_header(&cinfo, TRUE);
    (void) jpeg_start_decompress(&cinfo);
    width = cinfo.output_width;
    height = cinfo.output_height;

    *img = calloc((size_t) width * height, sizeof(pixel_rgb_t));
   
    pixel_rgb_t *current_pixel = *img;
    if (!*img) {
        printf("NO MEM FOR JPEG CONVERT!\n");
        exit(1);
    } 

    row_stride = width * cinfo.output_components;
    pJpegBuffer = (*cinfo.mem->alloc_sarray)
            ((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

    while (cinfo.output_scanline < cinfo.output_height) {
        (void) jpeg_read_scanlines(&cinfo, pJpegBuffer, 1);
        for (int x = 0; x < width; x++) {
            r = pJpegBuffer[0][cinfo.output_components * x];
            if (cinfo.output_components > 2) {
                g = pJpegBuffer[0][cinfo.output_components * x + 1];
                b = pJpegBuffer[0][cinfo.output_components * x + 2];
            } else {
                g = r;
                b = r;
            }

            //r, g and b contain the color information for the channels read, green and blue
            // current_pixel is your current pixel to fill with info from the jpeg.

           // at first we collect the current values , of the color channels

           pixel_rgb_t read_Channel_Values = {r, g, b} ;

            // we do save the values of the colors, at that place in memory
            // where current_pixel is pointing to 

           *current_pixel = read_Channel_Values;
        
           // we do increment the "pixel" pointer to the next 
           // "reserved" memory

           current_pixel++;
        }
    }


    fclose(infile);
    (void) jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);

    size->height = (uint32_t) height;
    size->width = (uint32_t) width;
}
/**
 * @brief Writes pixel data to a JPEG file with 80% quality and defined image size.
 * @param pixel_data the pixel to compress
 * @param size the size of this image
 * @param filename paht to write this file to.
 */
void save_jpeg(const pixel_rgb_t *pixel_data, const image_size_t size, const char *filename) {
 
 
    // at first we open a certain file, that shall later contain the 
    // read image 
 
    // if fopen succeedes, we will get some file descriptor 

    FILE *outfile = fopen(filename, "wb");

    // if it fails, we will receive some error message and the application shuts down 
    if (!outfile) {
        fprintf(stderr, "can't open %s\n for write", filename);
        exit(1);
    }

    // here we set up libjpeg
    struct jpeg_compress_struct jpeg_info;
    struct jpeg_error_mgr jpeg_error;

    jpeg_info.err = jpeg_std_error(&jpeg_error);
    jpeg_create_compress(&jpeg_info);


    // here we put the output file, as the target of the compressed
    // image 
    jpeg_stdio_dest(&jpeg_info, outfile);

    jpeg_info.image_width = size.width;
    jpeg_info.image_height = size.height;
    jpeg_info.input_components = 3;
    jpeg_info.in_color_space = JCS_RGB;

    // set up libjpeg further 
    jpeg_set_defaults(&jpeg_info);

    // here the quality of tje image compression is set to 80 percent
    jpeg_set_quality(&jpeg_info, 80, true);

    // the compression starts 
    jpeg_start_compress(&jpeg_info, true);

    JSAMPROW row_pointer;

    pixel_rgb_t p;

    // here we do allocate some memory, that will contain one, certain scanline

    // row points to the "start" of it
    unsigned char *row = malloc(sizeof(unsigned char) * 3 * size.width);
   
    /**
     * At this point the input "image" file 
     * was read into the memory.
     * 
     * The image, that is internally build 
     * as some matrix of pixel, is read as a large 
     * array of these pixel. 
     * 
     * Precisely, the rows of the matrix are leade 
     * linewise. These Scanlines, are append after each other 
     * 
     * Example: 
     * 
     * -> Pixel | Pixel | Pixel ... 
     * 
     * (Pixel is a combinaiton of some ammount of red, green, blue)
     * 
     * -> red|green|blue|red|green|blue|red...
     * 
    */

    while (jpeg_info.next_scanline < jpeg_info.image_height) {

        // at first we will save a "working" copy , of the row pointer 
        unsigned char *current = row;

        //this is the index of the beginning of the current row in your source array.
        unsigned int current_row = jpeg_info.next_scanline * size.width;

        //....
        unsigned int next_row = (jpeg_info.next_scanline + 1) * size.width;
 
        unsigned int ctr = 0;
 
        /**
         * This loop reads the loaded image , pixelwise. 
         * 
         * The image , into the memory, is made of the scanned lines
         * of the read image.
         * 
         * So we will use current_row  as a delimeter, to manage the access
         * to the safed memory. 
         * 
         * A certain pixel_data[itr], does contain the different ammounts of the colors red, 
         * green and blue, of a colored point, that is used to build the image. 
         * 
         * This point contains 24 Bit, which is build of 8 bit, per color. 
         * 
         *  
        */

        for(unsigned int itr = current_row; itr < next_row; itr++){

            // we will safe, each color ammount 
            // in one certain index of the current pointer

            // current points to the same, memory location, that row is pointing to
            // so after the memory is successfully loaded with image "information"....
            current[ctr ] = pixel_data[itr].amountOfRed;
            current[(ctr + 1)] = pixel_data[itr].amountOfGreen;
            current[(ctr + 2)] = pixel_data[itr].amountOfBlue;
  
            ctr = ctr + 3;
        }
           
        row_pointer = (JSAMPROW) row;
  

        // ... we can save it to the output file ...
        jpeg_write_scanlines(&jpeg_info, &row_pointer, true);
    }

    // we will free the claimed memory 
    free(row);

    // we will tear down the libjpeg set up, that was build above 

    jpeg_finish_compress(&jpeg_info);
 
    jpeg_destroy_compress(&jpeg_info);
}



/**
 * @brief function that shall manage the image loading and file saving 
 * @param (char *) pointer to the input file 
 * @param (char *) pointer to the output file 
 * @param (int) desired width of an output file 
 * @param (int) desired height  of an output file 
 */

void saveFile(char *inputFile, char *outputFile, int width, int height){

    // we prepare some set up, for furhter processing
 
    // we initialize the struct, that sahll be adjusted later 
    image_size_t src_sz = {0, 0};

   

    // we initialize some pointer, that shall later reserve some memeory 
    // for a image 
    pixel_rgb_t *in; 
    
    // at first , we will load the image into the memory , and we willl adjsut the size 
    load_jpeg(inputFile, &in , &src_sz);

    float aspected_ratio;

    if(width == 0){

        aspected_ratio =  (float) src_sz.width / (float) src_sz.height;

        width = height * aspected_ratio;
    }
    else if(height == 0){

        aspected_ratio = (float) src_sz.height / (float) src_sz.width;

        height =  width * aspected_ratio;
    }


    //  
    image_size_t trgt_sz = {  width,  height};


    pixel_rgb_t *out = calloc((size_t) width * height, sizeof(pixel_rgb_t));
 
    resize_image( in , out, src_sz, trgt_sz );
 
    // after that, we can save the memory content to some file (specified by outputFile)
    save_jpeg(out , trgt_sz , outputFile);
}

/*
 * @brief this function shall validate some parameter, that shall describe a diemension of an output file 
 * @return integer value, that describe, if some input is valid (1 if valid, 0 if not )
*/

void validateInput(int sizeParameter){

    // an image cannot hae a negativ dimension, or a zero

    if(!(sizeParameter >= 1)){

        printf("invalid input \n");
        exit(1);
    }
}


int main(int argc, char **argv) 
{

    char arguments; 

    char *inputFile = "Input Filename"; 

    char *outputFile = "Output Filename"; 

    int width , height = 0; 
    // we will provide a way to load parameter for input/output files 

    while ((arguments = getopt(argc, argv, "i:o:w::h::")) != -1)
    {

      switch (arguments)
      { 
         case 'i':
            inputFile = argv[2];
            break;  /* input filename added */
          
         case 'o':
            outputFile = argv[4];        
            break; /* output filename added */

          case 'w':     
            width = atoi(argv[6]);
            validateInput(width);
            break; 

          case 'h':                  
            height =  atoi(argv[6]);
            validateInput(height);     
            break;

          default: 
            printf("invalid input \n"); 
            exit(1);
            break; /* program shall temrinate*/
 
        }
      }

    saveFile(inputFile, outputFile, width, height);
 
  
    return 0;
}
