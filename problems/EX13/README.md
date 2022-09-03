#### 依據實驗板的6個七段顯示器電路，設計一個七段顯示器掃描輸出控制程式，在實驗板上顯示「8951□□」與「□□□□□□」之交替顯示數字，其中□表示全部熄滅的意思，詳如下圖說明：
![圖片](https://user-images.githubusercontent.com/103128273/188279990-d2ca5584-b6a3-44a5-a385-600f3cbc7fe1.png)

    a. 將上列程式的Delay函數的延遲時間改為0.4ms，觀察觀察七段顯示器掃輸出的閃爍情況
    b. 將上列程式改為只有5在閃爍的狀況，如下圖說明
![圖片](https://user-images.githubusercontent.com/103128273/188280089-399e5c4f-2b47-4833-ab8b-27ef3cb08b67.png)

    c. 將上列程式的Delay函數改用計時器0模式1的方式，實現出七段顯示器的閃爍輸出控制程式