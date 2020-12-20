#ifndef AI_WAV_H_
#define AI_WAV_H_

typedef struct _aiwav_riff {
    char chunk_id[4];
    // 36 + sub_chunk2_size
    uint32_t chunk_size;
    char format[4];
} aiwav_riff_t;

typedef struct _aiwav_fmt {
    char sub_chunk1_id[4];
    uint32_t sub_chunk1_size;
    uint16_t audio_format;
    uint16_t num_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
} aiwav_fmt_t;

typedef struct _aiwav_data {
    char sub_chunk2_id[4];
    uint32_t sub_chunk2_size;
} aiwav_data_t;

typedef struct _aiwav {
   aiwav_riff_t riff;
   aiwav_fmt_t fmt;
   aiwav_data_t data;
} aiwav_t;

#endif /* AI_WAV_H_ */
