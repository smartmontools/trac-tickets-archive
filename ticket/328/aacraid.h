/* aacraid.h
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * You should have received a copy of the GNU General Public License
 * (for example COPYING); If not, see <http://www.gnu.org/licenses/>.
 *
 * This code was originally developed as a Senior Thesis by Michael Cornwell
 * at the Concurrent Systems Laboratory (now part of the Storage Systems
 * Research Center), Jack Baskin School of Engineering, University of
 * California, Santa Cruz. http://ssrc.soe.ucsc.edu/
 *
 */

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
   #define ENVIRONMENT64
#else
   #define ENVIRONMENT32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
    #define ENVIRONMENT64
#else
    #define ENVIRONMENT32
#endif
#endif




#define SRB_FUNCTION_EXECUTE_SCSI 0X00

#define METHOD_BUFFERED 0
#define METHOD_NEITHER  3

#define CTL_CODE(function, method) ( (4<< 16) | ((function) << 2) | (method) )   

#define FSACTL_SEND_RAW_SRB                     CTL_CODE(2067, METHOD_BUFFERED)

#define         SRB_DataIn               0x0040
#define         SRB_DataOut              0x0080
#define         SRB_NoDataXfer           0x0000

   
typedef struct{
        uint32_t lo32;
        uint32_t hi32;
    }address64;

    typedef struct{
        address64 addr64;
        uint32_t length;  /* Length. */
    }user_sgentry64;
    
typedef struct{
        uint32_t aadr32;
        uint32_t length;
    }user_sgentry32;
    
typedef struct  {
        uint32_t    count;
        user_sgentry64     sg64[1];
    }user_sgmap64;

typedef struct {
        uint32_t  count;
        user_sgentry32    sg32[1];
    }user_sgmap32;

    
typedef struct 
    {
        uint32_t function;           //SRB_FUNCTION_EXECUTE_SCSI 0x00
        uint32_t channel;            //bus
        uint32_t id;                 //use the ID number this is wrong
        uint32_t lun;                //Logical unit number
        uint32_t timeout;
        uint32_t flags;              //Interesting stuff I must say
        uint32_t count;              // Data xfer size
        uint32_t retry_limit;        // We shall see
        uint32_t cdb_size;           // Length of CDB
        uint8_t  cdb[16];            // The actual cdb command
        user_sgmap64 sg64;  // pDatabuffer and address of Databuffer
    }user_aac_srb64;

   
typedef struct 
    {
        uint32_t function;           //SRB_FUNCTION_EXECUTE_SCSI 0x00
        uint32_t channel;            //bus
        uint32_t id;                 //use the ID number this is wrong
        uint32_t lun;                //Logical unit number
        uint32_t timeout;
        uint32_t flags;              //Interesting stuff I must say
        uint32_t count;              // Data xfer size
        uint32_t retry_limit;        // We shall see
        uint32_t cdb_size;           // Length of CDB
        uint8_t  cdb[16];            // The actual cdb command
        user_sgmap32 sg32;  // pDatabuffer and address of Databuffer
    }user_aac_srb32;



   typedef struct 
    {
        uint8_t error_code;           /*70h (current errors),71h(deferred errors)*/
        uint8_t valid:1;             /*A valid bit of one indicates that information 
                                  field contains valid information as defined in 
                                  the SCSI 2 Standard*/
        uint8_t segment_number;      /*Only used for COPY, COMPARE ,or COPY AND VERIFY commands*/
        uint8_t sense_key:4;         /*Sense Key*/
        uint8_t reserved:1;          
        uint8_t ILI:1;               /*Incorrect Length Indicator*/
        uint8_t EOM:1;               /*End of Medium - reserved for random acess devices*/
        uint8_t filemark:1;          /*Filemark - reserved for random acces devices*/
        uint8_t information[4];      /*for direct-access devices,contains the unsigned logical
                                  block address or residure associated with the sense key*/
        uint8_t add_sense_len;       /*number of additional sense bytes to follow this field*/
        uint8_t cmnd_info[4];        /*not used*/
        uint8_t ASC;                 /*Additional Sense Code*/
        uint8_t ASCQ;                /*Additional Sense Code Qualifier*/
        uint8_t FRUC;                /*Field Replacement  Unit Code - not used*/
        uint8_t bit_ptr:3;           /*Indicates which byte of the CDB or parameter data was in error*/


        uint8_t BPV:1;               /* bit pointer valid(BPV):1- indicates that the bit_ptr         field                               has                                 valid value*/

        uint8_t reserved2:2;        
        uint8_t CD:1;                /*Command data bit:1 - illegal parameter in CDB
                                  0-illegal parameter in data*/
        uint8_t SKSV:1;              
        uint8_t field_ptr[2];       /*byte of CDB  or parameter data in error*/
    }sense_data;

    typedef struct
    {
        uint32_t status;
        uint32_t srb_status;
        uint32_t scsi_status;
        uint32_t data_xfer_length;
        uint32_t sense_data_size;
        uint8_t  sense_data[30];
    }user_aac_reply;



