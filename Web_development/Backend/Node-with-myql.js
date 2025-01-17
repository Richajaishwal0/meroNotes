let mysql=require('mysql')

var con=mysql.createConnection({
    host:"localhost",
    user:"root",
    password:"........."
});
con.connect((err)=>{
    if (err)
    {
        console.error(err);
    }
    else 
    {
        console.log("Connected");
        let sql="use nodesql"
        con.query(sql,(err,result)=>{
            if (err) 
            {
                console.error(err);
            }
            else{
                console.log("Result:",result);
            }
          
        });
        // let create="create table form(Name varchar(20),age int,Contact int,email varchar(50))";
        // con.query(create,(err,result)=>{
        //     if (err)
        //     {
        //         console.error(err);
        //     }
        //     else{
        //         console.log("Created");
        //     }
        // });
        let dis="select * from form where age=28;"
        con.query(dis,(err,result,fields)=>
        {
            if (err)
                {
                    console.error(err);
                }
                else{
                    console.log("Result",result);
                } 
        })
    }
    
    });  
    
   
