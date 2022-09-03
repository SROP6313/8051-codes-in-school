#### 設計一個具有主程式與中斷副程式的程式，主程式只具有參數初始化功能，提供一個全域變數push去記錄按鈕次數，並將push值透過LED燈以二進制顯示該值。而按鈕PB1 (P3.3, INT 1) 必須使用中斷方法，待中斷發生後再執行按鈕記錄， 讓push變數值增加1。注意，本範例要應用軟體方式防止按鈕彈跳問題。
    a. 若希望將此程式改為初始值由10開始遞增，則程式該如何修改？
    b. 若希望將此程式改為遞減，則程式該如何修改？
    c. 若希望將此程式改為每次中斷觸發時暫存器自動加10，則程式該如何修改？