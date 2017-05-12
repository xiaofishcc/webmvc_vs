using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;

namespace Servicejiafa
{
    /// <summary>
    /// Servicejiafa 的摘要说明
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // 若要允许使用 ASP.NET AJAX 从脚本中调用此 Web 服务，请取消注释以下行。 
    // [System.Web.Script.Services.ScriptService]
    public class Servicejiafa : System.Web.Services.WebService
    {

        [WebMethod(Description = @"加法计算<br/>
                                   请求参数:<br/> 
                                   x:int类型<br/>  
                                   y:int类型<br/> 
                                   sum:<br/>
                                   error_code:信息编码<br/>   
                                   版本信息:V1 20170512 开发者:xiaofishcc<br/>
                        ")]
      public int Add(int x,int y)
        {
            int sum;
            sum = x + y;
            return sum;
        }

    }
}
