# Frieder Ferlemann: this gnuplot script makes sense for data from SSD drives with Indilinx controllers

set term png size 1600,1200
set output "sm_all.png"

#set xrange [1000:]

set multiplot layout 4,2

set tics nomirror
set mxtics
set mytics
set y2tics
set my2tics

set key left

#set output "sm1.png"
set title "STT_FTM64GX25H Write_Sectors_Tot_Ct and Average_Erase_Count over POH"
set xlabel "Power_On_Hours"
set ylabel "Write_Sectors_Tot_Ct"
set y2label "Average_Erase_Count"
plot "sm.dat" using 1:2 ps 0.3 lc 2 title "Write_Sectors_Tot_Ct", \
     ""       using 1:8 ps 0.6 lc 1 title "Average_Erase_Count" axis x1y2


#set output "sm2.png"
set title "STT_FTM64GX25H Bytes written and Bytes erased over POH\nGarbage collection running wild?"
set ylabel "GByte written"
set y2label "GByte erased"
media_size=2^36
plot "sm.dat" using 1:($2) * 512 / 1E9  ps 0.3 lc 2 title "written", \
     ""       using 1:($8) * media_size ps 0.6 lc 1 title "erased" axis x1y2


#set output "sm3.png"
set title "STT_FTM64GX25H Error Count over POH"
set ylabel "Error Count"
set y2label "Average_Erase_Count"
#set key bottom right
plot "sm.dat" using 1:($4) ps 0.3 title "Error_Bits_Flash_Tot_Ct", \
     ""       using 1:($5) ps 0.3 title "Corr_Read_Errors_Tot_Ct", \
     ""       using 1:($8) w l lw 0.1 title "Average_Erase_Count" axis x1y2

#set output "sm4.png"
set title "STT_FTM64GX25H Lifetime Guesses over POH\n(based on Max_PE_Count_Spec=10000) (expect glitches)"
set ylabel "Remaining_Lifetime_Perc"
set y2label "Estimated Lifetime Hours"
Max_PE_Count_Spec=10000
plot "sm.dat" using 1:($9)                                        ps 0.3 title "Remaining_Lifetime_Perc (drive)", \
     ""       using 1:(100-100*($8)/(Max_PE_Count_Spec))          ps 0.3 title "Remaining_Lifetime_Perc (calc)", \
     ""       using 1:($1)*100/(100-(($9)==100?99.5:($9)))        ps 0.3 title "Estimated Lifetime (calc1)" axis x1y2, \
     ""       using 1:($1)*(Max_PE_Count_Spec)/(($8)==0?0.5:($8)) ps 0.3 title "Estimated Lifetime (calc2)" axis x1y2

#set output "sm5.png"
set title "STT_FTM64GX25H Write_Sectors_Tot_Ct and Write_Commands_Tot_Ct over POH"
set ylabel "Write_Sectors_Tot_Ct"
set y2label "Write_Commands_Tot_Ct"
set key bottom right
plot "sm.dat" using 1:2 ps 0.3 title "Write_Sectors_Tot_Ct", \
     ""       using 1:3 ps 0.3 title "Write_Commands_Tot_Ct" axis x1y2

#set output "sm6.png"
set title "STT_FTM64GX25H Erase Count over POH"
set ylabel "Erase Count"
set y2label ""
set key bottom right
plot "sm.dat" using 1:7 ps 0.3 title "Max_Erase_Count", \
     ""       using 1:8 ps 0.3 title "Average_Erase_Count", \
     ""       using 1:6 ps 0.3 title "Min_Erase_Count"

#set output "sm7.png"
set xrange [0:]
set title "STT_FTM64GX25H Error Count over Average_Erase_Count"
set ylabel "Error Count"
set y2label "Power_On_Hours"
set xlabel "Average_Erase_Count"
#set key bottom right
plot "sm.dat" using 8:($4)     ps 0.3 title "Error_Bits_Flash_Tot_Ct", \
     ""       using 8:($5)     ps 0.3 title "Corr_Read_Errors_Tot_Ct", \
     ""       using 8:($1) w l lw 0.1 title "Power_On_Hours" axis x1y2

#set output "sm8.png"
set title "STT_FTM64GX25H Error Count over Write_Sectors_Tot_Ct"
set ylabel "Error Count"
set y2label "Power_On_Hours"
set xlabel "Write_Sectors_Tot_Ct"
#set key bottom right
plot "sm.dat" using 2:($4)     ps 0.3 title "Error_Bits_Flash_Tot_Ct", \
     ""       using 2:($5)     ps 0.3 title "Corr_Read_Errors_Tot_Ct", \
     ""       using 2:($1) w l lw 0.1 title "Power_On_Hours" axis x1y2
