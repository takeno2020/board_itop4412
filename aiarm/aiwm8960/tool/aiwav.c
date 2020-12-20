#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "aiwav.h"

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
    aiwav_t wav;
    aiwav_riff_t riff;
    aiwav_fmt_t fmt;
    aiwav_data_t data;

    if (argc != 2) {
        printf("Usage: %s <wav file>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("can't open audio file\n");
        exit(1);
    }

    fread(&wav, 1, sizeof(wav), fp);
    riff = wav.riff;
    fmt = wav.fmt;
    data = wav.data;

    printf("******************** RIFF ********************\n");
    printf("ChunkID      : %c%c%c%c\n", riff.chunk_id[0], riff.chunk_id[1],
                                        riff.chunk_id[2], riff.chunk_id[3]);
    printf("ChunkSize    : %d\n", riff.chunk_size);
    printf("Format       : %c%c%c%c\n", riff.format[0], riff.format[1],
                                        riff.format[2], riff.format[3]);
    printf("\n");
    
    printf("******************** fmt  ********************\n");
    printf("Subchunk1ID  : %c%c%c%c\n", fmt.sub_chunk1_id[0], fmt.sub_chunk1_id[1],
                                        fmt.sub_chunk1_id[2], fmt.sub_chunk1_id[3]);
    printf("Subchunk1Size: %d\n", fmt.sub_chunk1_size);
    printf("AudioFormat  : %d\n", fmt.audio_format);
    printf("NumChannels  : %d\n", fmt.num_channels);
    printf("SampleRate   : %d\n", fmt.sample_rate);
    printf("ByteRate     : %d\n", fmt.byte_rate);
    printf("BlockAlign   : %d\n", fmt.block_align);
    printf("BitsPerSample: %d\n", fmt.bits_per_sample);
    printf("\n");

    printf("******************** data ********************\n");
    printf("blockID      : %c%c%c%c\n", data.sub_chunk2_id[0], data.sub_chunk2_id[1],
                                        data.sub_chunk2_id[2], data.sub_chunk2_id[3]);
    printf("blockSize    : %d\n", data.sub_chunk2_size);
    printf("\n");
	
    printf("duration     : %d\n", data.sub_chunk2_size / fmt.byte_rate);
    return EXIT_SUCCESS;
}
