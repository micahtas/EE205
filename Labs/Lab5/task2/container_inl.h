inline bool Container::isempty() const
/*  tests if a Container is empty
 *  pre:  Container has been created
 *  post: returns true if Container is empty; false otherwise
 *  */
{
        if(count == 0)   
        {return true;}                                        
        else                                                  
        {return false;}                                       
}                                                             
                                                              
inline bool Container::isfull() const                         
/*  tests if a Container is full                              
 *  pre:  Container has been created                          
 *  post: returns true if Container is full; false otherwise  
 *  */                                                        
{                                                             
        if(count > MAXSIZE)                                   
        {return true;}                                        
        else                                                  
        {return false;}                                       
}                                                             
                                                              
inline int Container::size() const                            
/*  determines the size of a Container                        
 *  pre:  Container has been created                          
 *  post: returns the number of entries in the Container      
 *  */                                                        
{                                                             
        return count;                                         
}                                                             
                                                              
inline void Container::clear()                                
/*  clear a Container object                                  
 *  pre:  Container has been created                          
 *  post: all entries have been removed; Container is empty   
 *  */                                                        
{                                                             
        Container();                                          
}           

