import mcc_pi.*
N1 = 10;

[tocke_v_krogu, tocke_v_kvadratu] = mcc_pi(N1);
 fprintf('Točke v krogu:\n');
    for i = 1:size(tocke_v_krogu, 2)
        fprintf('(x=%.6f, y=%.6f)\n', tocke_v_krogu(1, i), tocke_v_krogu(2, i));
    end

 fprintf('Točke v kvadratu:\n');
    for i = 1:N1
        fprintf('(x=%.6f, y=%.6f)\n', tocke_v_kvadratu(1, i), tocke_v_kvadratu(2, i));
    end

pravi_pi = pi;
N = 10000;
for i = 1:2
    [tocke_v_krogu, skupno_stevilo_tock] = mcc_pi(N);
    [prib_pi, napaka] = area_pi(tocke_v_krogu, skupno_stevilo_tock, pravi_pi);

    fprintf('Število točk: %d, Približek za π: %.6f, Napaka: %.6f\n', N, prib_pi, napaka);
    N = N * 10;
end

function [prib_pi, napaka] = area_pi(tocke_v_krogu, tocke_v_kvadratu, pravi_pi)

    prib_pi = 4 * numel(tocke_v_krogu) / numel(tocke_v_kvadratu);
    napaka = prib_pi - pravi_pi;
end