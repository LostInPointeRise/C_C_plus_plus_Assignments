#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <jpeglib.h>
#include <stdbool.h> 

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
 * @brief Loads pixels from a JPEG file into memory.
 * @param name the path of the file to read
 * @param img pointer to pixel data. Will be allocated.
 * @param size the size of the image. Will be set by this function
 */
void load_jpeg(const char *name, pixel_rgb_t **img, image_size_t *const size) {
    uint8_t r, g, b;
    
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
  
  // the dimensions ar enow given as parameter values 
  //  width = cinfo.output_width;   
  //  height = cinfo.output_height;

     
    *img = calloc((size_t) size->width * size->height, sizeof(pixel_rgb_t));
   
    pixel_rgb_t *current_pixel = *img;
    if (!*img) {
        printf("NO MEM FOR JPEG CONVERT!\n");
        exit(1);
    }

    row_stride = size->width * cinfo.output_components;
    pJpegBuffer = (*cinfo.mem->alloc_sarray)
            ((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

    while (cinfo.output_scanline < cinfo.output_height) {
        (void) jpeg_read_scanlines(&cinfo, pJpegBuffer, 1);
        for (int x = 0; x < size->width; x++) {
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
    image_size_t size = {0, 0};

    // we initialize some pointer, that shall later reserve some memeory 
    // for a image 
    pixel_rgb_t *img;


    size.height = (uint32_t) height;
    size.width = (uint32_t) width;

    // at first , we will load the image into the memory 
    load_jpeg(inputFile, &img , &size);
 
    // after that, we can save the memory content to some file (specified by outputFile)
    save_jpeg(img , size, outputFile);
}

/*
 * @brief this function shall validate some parameter, that shall describe a diemension of an output file 
 * @return integer value, that describe, if some input is valid (1 if valid, 0 if not )
*/

int validateInput(int sizeParameter){

    // an image cannot hae a negativ dimension, or a zero

    return (sizeParameter >= 1) ? 1 : 0; 

}


int main(int argc, char **argv) 
{

    char arguments; 

    char *inputFile = "Input Filename"; 

    char *outputFile = "Output Filename"; 

    int width , height = 0; 
    // we will provide a way to load parameter for input/output files 

    while ((arguments = getopt(argc, argv, "i:o:w:h:")) != -1)
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
            break;  /*  adding width dimension, atoi will return 0, if a non numerical value was entered */
         
         case 'h':
            height = atoi(argv[8]);        
            break;  /*  adding height dimension, atoi will return 0, if a non numerical value was entered */
            
         default: 

            break; /* program shall temrinate*/
      }

    }

    if(validateInput(width) && validateInput(height)){

        saveFile(inputFile, outputFile, width, height);
    }
    else{

        printf("invalid input \n");
        exit(1);
    }

    return 0;
}
