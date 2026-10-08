// This programme reads SMART values and decodes
// Head_Flying_Hours from my ST31000528AS.
// Put this file in the smartmontools tree.
#include <stdio.h>

#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#include "atacmds.h"

#define HDIO_GET_IDENTITY   0x030d  /* get IDE identification info */
#define HDIO_DRIVE_TASK             0x031e  /* execute task and special drive command */
#define HDIO_DRIVE_CMD              0x031f  /* execute a special drive command */

#define BUFFER_LENGTH (4+512)

using namespace std;
int main(int ac, char* av[]) {
	time_t t;
	int i;
	int fd;
	int rc;
	unsigned short deviceid[256];
	unsigned char buf[BUFFER_LENGTH];

	struct ata_smart_attribute *attrs;
	struct ata_smart_values	*values;

	fd=open("/dev/sda", O_RDONLY|O_NONBLOCK);
	if(fd < 0) {
		perror("open");
	}

	memset(deviceid, 0, sizeof(deviceid));
	rc = ioctl(fd, HDIO_GET_IDENTITY, deviceid);
	if( -1 == rc) {
		perror("ioctl");
	}

	while(1) {
		memset(buf, 0, sizeof(buf));
		buf[0]=ATA_SMART_CMD;
		buf[2]=ATA_SMART_READ_VALUES;
		buf[3]=1;
		t=time(NULL);
		rc = ioctl(fd, HDIO_DRIVE_CMD, buf);
		if( -1 == rc) {
			perror("ioctl");
		}
		values = (struct ata_smart_values*)(buf+4);
		for (i = 0; i < NUMBER_ATA_SMART_ATTRIBUTES; ++i) {
			if(240 != values->vendor_attributes[i].id) continue;
			printf("%d\t", t);
			printf("0x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x\n",
				values->vendor_attributes[i].raw[3],
				values->vendor_attributes[i].raw[2],
				values->vendor_attributes[i].raw[1],
				values->vendor_attributes[i].raw[0],
				values->vendor_attributes[i].reserv,
				values->vendor_attributes[i].raw[5],
				values->vendor_attributes[i].raw[4]
				);
		}
		sleep(10);
	}
	close(fd);
}
