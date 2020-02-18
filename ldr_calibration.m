clear all
clc
tension = [1.36 1.4 1.42 1.5 1.61 1.94 2.49 2.77 2.4 1.89 2.65 2.97 3.15 3.24 3.46 3.55];
lux = [164 174 182 199 253 362 590 652 517 360 860 698 850 910 1040 1170];
%%

lux = [210 277 344 385 455 505 560 615 640 722 770 836 860];
tension = [1.03 1.35 1.67 1.89 2.20 2.5 2.6 03.04 3.12 3.53 3.74 4.07 4.20];

%y = p1*x + p2;
p1 = 204.93;
p2 = 1.4485;

residuals = 29.59;

%%
plot(tension, lux, 'o');
title('LDR Sensor Calibration')
xlabel('Tension');
ylabel('Lux');