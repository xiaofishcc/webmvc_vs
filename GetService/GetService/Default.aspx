<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="GetService.Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    第一：<asp:TextBox ID="txtValue1" runat="server"></asp:TextBox>
        <br />
    第二：<asp:TextBox ID="txtValue2" runat="server"></asp:TextBox>
        <br />
    求和：<asp:TextBox ID="txtSum" runat="server"></asp:TextBox>
        <br />
        <asp:Button ID="btnOk" runat="server" Text="WEbdd" OnClick="btnOk_Click"/>
    </div>
    </form>
</body>
</html>
