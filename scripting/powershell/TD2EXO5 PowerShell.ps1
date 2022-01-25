cd 'HKLM:cd Software\Microsoft\Windows NT\CurrentVersion\NetworkCards'
$cle = ls
$sn = $cle.getValue("ServiceName")
cd \System\CurrentControlSet\Services\Tcpip\Parameters\Interfaces
$cle = ls | where-object { $_.pschildname -eq $sn }
$cle.getValue("DHCPIPAddress")
