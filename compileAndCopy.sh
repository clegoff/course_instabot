make clean; make;
sudo mount /dev/sda /media/nucleo;
sudo cp .build/course_instabot401_2.bin /media/nucleo/;sync;
sudo umount /media/nucleo
