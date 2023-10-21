function [tocke_v_krogu, tocke_v_kvadratu] = mcc_pi(N)

    x = 10 * rand(1,N); %višina kvadrata-nakljucno
    y = 10 * rand(1,N); %sirina kvadrata-nakljucno

    k=sqrt((x-5).^2 + (y-5).^2) <= 5; %radij krožnice
    
    tocke_v_krogu = [x(k); y(k)];
    tocke_v_kvadratu = [x; y];
    
end
