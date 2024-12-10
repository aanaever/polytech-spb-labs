program lab_2_18
   use Environment
   use Source_Process
   use Source_IO

   implicit none
   character(:), allocatable :: F1, F2
   type(SourceLine), pointer        :: Code  => Null() 
   type(SourceLine), pointer        :: Diff => Null()
   
                       
            
   F1 = "../data/source.f90"
   
   F2 = "source.f90.diff"
   
   Code => Read_Source_Code(F1)
   call Output_Source_Code(F2, Code, "Исходный список:", "rewind")
  
  if (Associated(Code)) then
      call List_Mask (Code, Diff)
      
      if (Associated(Diff)) &
      call Output_Source_Code(F2, Diff, "Список файлов wi*.* :", "append")
   end if

end program lab_2_18
